in#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Ascertain key is valid
        if (strlen(argv[1]) == 26)
        {
            //Check for duplicate characters (case-insensitive)
            int matches = 0;

            for (int i = 0; i < 26; i++)
            {
                // Check if contain non-alphabet
                if (!isalpha(argv[1][i]))
                {
                    printf("Key must contain only 26 characters.\n");
                    return 1;
                }

                for (int j = 0; argv[1][j] != '\0'; j++)
                {
                    if (argv[1][j] == argv[1][i])
                    {
                        matches++;
                    }
                }
            }
            if (matches != 26)
            {
                printf("Do not repeat letters in key.\n");
                return 1;
            }

            string text = get_string("Enter text:");
            printf("ciphertext: ");

            string key = (argv[1]);
            int n = strlen(text);

            for (int i = 0; i < n; i++)
            {
                // checking if it is lowercase 97 = a to 112 = z
                if (text[i] >= 'a' && text[i] <= 'z')
                {
                    int letter = (text[i] - 'a');
                    printf("%c", tolower(key[letter]));
                }
                else if (text[i] >= 'A' && text[i] <= 'Z')
                {
                    int letter = (text[i] - 'A');
                    printf("%c", toupper(key[letter]));
                }
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
            return 0;

        }
        else
        {
            printf("Key must contain 26 characters. \n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    return 0;
}