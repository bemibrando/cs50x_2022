#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

int main()
{
    printf("hello, world\n");

    string text = get_string("Paste a text to calculate the readability \n");
    int textLength = strlen(text);
    float countChar = 0.0f, countWords = 0.0f, countSentences = 0.0f;

    // Count char per words and word per senteces and sentences quantity
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] != 0)
        {
            if (text[i] == '!' || text[i] == '?' || text[i] == '.')
            {
                countWords++;
                countSentences++;
                i++;
            }
            else if (text[i] == ' ')
            {
                countWords++;
            }
            else if (text[i] == '-' || text[i] == ',' || text[i] == '\'' || text[i] == '"' || text[i] == ':')
            {

            }
            else
            {
                countChar++;
            }
        }
    }

    //printf("char: %f\nwords: %f\nsentences: %f\n", countChar, countWords, countSentences);

    // index = 0.0588 * L - 0.296 * S - 15.8
    // L = the average number of letters per 100 words
    // S = the average number of sentencer per 100 words
    float L = countChar / countWords * 100;
    float S = countSentences / countWords * 100;

    //printf("L: %f\nS: %f\n", L, S);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}