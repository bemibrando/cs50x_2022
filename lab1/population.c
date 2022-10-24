#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

#define MIN 9

int main()
{
    int startLhamas = 0, endLhamas = 0;

    printf("Hello!\n");

    do
    {
        startLhamas = atoi(get_string("How many lhamas do you have?\n"));
    } while (startLhamas < MIN);

    do
    {
        endLhamas = atoi(get_string("How many lhamas do you want to have?\n"));
    } while (endLhamas < startLhamas);


    int years = 0;

    // Calculate how many years you will need to achive your total lhama
    while (startLhamas < endLhamas)
    {
        // New Lhamas born
        int nBorn = startLhamas / 3;

        // Lhamas pass away
        int nPass = startLhamas / 4;
        startLhamas += nBorn - nPass;

        years++;
    }

    printf("Years: %d\n", years);
    printf("You will need %d years\n", years);

}