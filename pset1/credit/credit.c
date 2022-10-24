#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long ccNumber = get_long("Type your credit card number: ");

    // Count ccNumber length
    int ccLength = 0;
    long cc = ccNumber;

    // while cc is major than 0 keep counting
    // so is number is 4321 and ccLength starts with 0
    // 0 | 4321 : 0
    // 1 | 432.1 : 1
    // 2 | 43.21 : 2
    // 3 | 4.321 : 3
    // 4 | 0.4321 : 4 -> while ends because cc is minor than 0 and ccLength is 4
    while (cc > 0)
    {
        cc = cc / 10;
        ccLength++;
    }

    // Check if ccLength is valid
    if (ccLength != 13 && ccLength != 15 && ccLength != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculate checksum
    int checkSum = 0;
    long checkCCNumber = ccNumber;

    if (ccLength % 2 == 0)
    {
        for (int i = (ccLength - 1); i >= 0; i--)
        {
            long powing = pow(10, i);
            if (i % 2 != 0)
            {
                int numb = checkCCNumber / powing;
                int mult = numb * 2;
                if (mult > 9)
                {
                    checkSum += 1 + (mult - 10);
                }
                else
                {
                    checkSum += mult;
                }
                checkCCNumber += -(numb * powing);
                //printf("numb: %d | checkSum: %d | checkCCNumb: %ld\n", numb, checkSum, checkCCNumber);
            }
            else
            {
                int numb = checkCCNumber / powing;
                checkSum += numb;
                checkCCNumber += -(numb * powing);
                //printf("numb: %d | checkSum: %d | checkCCNumb: %ld\n", numb, checkSum, checkCCNumber);
            }
        }
    }
    else
    {
        for (int i = (ccLength - 1); i >= 0; i--)
        {
            long powing = pow(10, i);
            if (i % 2 == 0)
            {
                int numb = checkCCNumber / powing;
                checkSum += numb;
                checkCCNumber += -(numb * powing);

                //printf("numb: %d | checkSum: %d | checkCCNumb: %ld\n", numb, checkSum, checkCCNumber);
            }
            else
            {
                int numb = checkCCNumber / powing;
                int mult = numb * 2;
                if (mult > 9)
                {
                    checkSum += 1 + (mult - 10);
                }
                else
                {
                    checkSum += mult;
                }
                checkCCNumber += -(numb * powing);
                //printf("numb: %d | checkSum: %d | checkCCNumb: %ld\n", numb, checkSum, checkCCNumber);
            }
        }
    }

    if (checkSum % 10 != 0)
    {
        // printf("%d ", checkSum);
        printf("INVALID\n");
        return 0;
    }

    // Get starting digits
    long start = ccNumber / pow(10, (ccLength - 2));

    // Next check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}