#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double average = 0;

            average += image[i][j].rgbtRed;
            average += image[i][j].rgbtGreen;
            average += image[i][j].rgbtBlue;

            average = round(average / 3);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int temp = 0;

            // Change RED position
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtRed = temp;

            // Change Green
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][width - 1 - j].rgbtGreen = temp;

            // Change Green
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            double averageRed = 0;
            double averageGreen = 0;
            double averageBlue = 0;

            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if (i + a < 0 || i + a >= height)
                    {
                        continue;
                    }
                    if (j + b < 0 || j + b >= width)
                    {
                        continue;
                    }

                    averageRed += temp[i + a][j + b].rgbtRed;
                    averageGreen += temp[i + a][j + b].rgbtGreen;
                    averageBlue += temp[i + a][j + b].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = round(averageRed / count);
            image[i][j].rgbtGreen = round(averageGreen / count);
            image[i][j].rgbtBlue = round(averageBlue / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int gy[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gx_red = 0;
            float gx_green = 0;
            float gx_blue = 0;
            float gy_red = 0;
            float gy_green = 0;
            float gy_blue = 0;

            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if (i + a < 0 || i + a >= height)
                    {
                        continue;
                    }
                    if (j + b < 0 || j + b >= width)
                    {
                        continue;
                    }

                    gx_red += temp[i + a][j + b].rgbtRed * gx[a + 1][b + 1];
                    gx_green += temp[i + a][j + b].rgbtGreen * gx[a + 1][b + 1];
                    gx_blue += temp[i + a][j + b].rgbtBlue * gx[a + 1][b + 1];

                    gy_red += temp[i + a][j + b].rgbtRed * gy[a + 1][b + 1];
                    gy_green += temp[i + a][j + b].rgbtGreen * gy[a + 1][b + 1];
                    gy_blue += temp[i + a][j + b].rgbtBlue * gy[a + 1][b + 1];
                }
            }

            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}