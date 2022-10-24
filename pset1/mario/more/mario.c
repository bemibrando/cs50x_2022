#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    printf("hello, world\n");

    int floors = 0;
    bool numbValid = false;

    while (numbValid == false)
    {
        floors = atoi(get_string("How many floors will your staircasase have?\n"));
        if (floors > 0 && floors < 9)
        {
            numbValid = true;
        }
    }

    for (int i = 0; i < floors; i++)
    {
        for (int j = 0; j < floors; j++)
        {
            int staircase = floors - i - 1;
            (staircase <= j) ? printf("#") : printf(" ");
        }
        printf("  ");
        for (int j = 0; j < floors; j++)
        {
            (j <= i) ? printf("#") : printf("");
        }

        printf("\n");
    }
}