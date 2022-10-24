#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float twentyFive = 0.25f, ten = 0.1f, five = 0.05f, one = 0.01f;

    float change = -1;

    do
    {
        change = get_float("How much change do you need?\n");

    } while (change < 0);

    int coinCounter = 0;

    printf("\n");
    do
    {
        change = round(change * 100) / 100;
        float coin = 0.0f;

        if (change >= twentyFive)
        {
            coin = twentyFive;
        }
        else if (change >= ten)
        {
            coin = ten;
        }
        else if (change >= five)
        {
            coin = five;
        }
        else if (change >= one)
        {
            coin = one;
        }
        else
        {
            break;
        }

        int result = floor(change / coin);
        printf("%f, coin: %d of %f \n", change, result, coin);
        change = change - (result * coin);
        coinCounter += result;
    } while (change > 0);

    printf("Total coins: %d\n", coinCounter);

    return 0;
}