// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node* table[N];

int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // Hash word to obtain hash value
    int hash_value = hash(word);

    // Access linked list at that index in hash table
    node* n = table[hash_value];

    // Traverse linked list, looking for word (strcasecomp)
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
// This Hash function divides the value k by M and then uses the remainder obtained.
// h(K) = k mod M
// k is the key value
// M is the size of the hash table.
unsigned int hash(const char* word)
{
    // Adds the ASCII values of all characters in the word together
    long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char* dictionary)
{
    // Open dictionary file (file to be load, action to do)
    FILE* dict_pointer = fopen(dictionary, "r");

    // Check if dictionary was openable
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // Initialise word array
    char next_word[LENGTH + 1];

    // Read strings from file one at a time untill last element
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // Create new node for each word
        node* newNode = malloc(sizeof(node));

        if (newNode == NULL)
        {
            return false;
        }

        // Copy word into node using strcopy
        strcpy(newNode->word, next_word);

        // Hash word to obtain hash value
        int hash_value = hash(next_word);

        // Insert node into hash table at that location
        newNode->next = table[hash_value];
        table[hash_value] = newNode;
        dict_size++;
    }
    fclose(dict_pointer);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        node* cursor = table[i];

        while (cursor)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}