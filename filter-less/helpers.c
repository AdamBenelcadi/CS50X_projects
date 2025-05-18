#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round(
                ((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((393.0 * image[i][j].rgbtRed + 769.0 * image[i][j].rgbtGreen +
                                  189.0 * image[i][j].rgbtBlue) /
                                 1000);
            int sepiaGreen = round((349.0 * image[i][j].rgbtRed + 686.0 * image[i][j].rgbtGreen +
                                    168.0 * image[i][j].rgbtBlue) /
                                   1000);
            int sepiaBlue = round((272.0 * image[i][j].rgbtRed + 534.0 * image[i][j].rgbtGreen +
                                   131.0 * image[i][j].rgbtBlue) /
                                  1000);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j < width / 2)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp;
            }
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                image[0][0].rgbtRed = round(((float) (copy[0][0].rgbtRed + copy[0][1].rgbtRed +
                                                      copy[1][0].rgbtRed + copy[1][1].rgbtRed)) /
                                            4);
                image[0][0].rgbtGreen =
                    round((float) (copy[0][0].rgbtGreen + copy[0][1].rgbtGreen +
                                   copy[1][0].rgbtGreen + copy[1][1].rgbtGreen) /
                          4);
                image[0][0].rgbtBlue = round((float) (copy[0][0].rgbtBlue + copy[0][1].rgbtBlue +
                                                      copy[1][0].rgbtBlue + copy[1][1].rgbtBlue) /
                                             4);
            }
            if (i == 0 && j == width - 1)
            {
                image[0][width - 1].rgbtRed =
                    round((float) (copy[0][width - 1].rgbtRed + copy[0][width - 2].rgbtRed +
                                   copy[1][width - 1].rgbtRed + copy[1][width - 2].rgbtRed) /
                          4);
                image[0][width - 1].rgbtGreen =
                    round((float) (copy[0][width - 1].rgbtGreen + copy[0][width - 2].rgbtGreen +
                                   copy[1][width - 1].rgbtGreen + copy[1][width - 2].rgbtGreen) /
                          4);
                image[0][width - 1].rgbtBlue =
                    round((float) (copy[0][width - 1].rgbtBlue + copy[0][width - 2].rgbtBlue +
                                   copy[1][width - 1].rgbtBlue + copy[1][width - 2].rgbtBlue) /
                          4);
            }
            if (i == height - 1 && j == 0)
            {
                image[height - 1][0].rgbtRed =
                    round((float) (copy[height - 1][0].rgbtRed + copy[height - 2][1].rgbtRed +
                                   copy[height - 2][0].rgbtRed + copy[height - 1][1].rgbtRed) /
                          4);
                image[height - 1][0].rgbtGreen =
                    round((float) (copy[height - 1][0].rgbtGreen + copy[height - 2][1].rgbtGreen +
                                   copy[height - 2][0].rgbtGreen + copy[height - 1][1].rgbtGreen) /
                          4);
                image[height - 1][0].rgbtBlue =
                    round((float) (copy[height - 1][0].rgbtBlue + copy[height - 2][1].rgbtBlue +
                                   copy[height - 2][0].rgbtBlue + copy[height - 1][1].rgbtBlue) /
                          4);
            }
            if (i == height - 1 && j == width - 1)
            {
                image[height - 1][width - 1].rgbtRed =
                    round((float) (copy[height - 1][width - 1].rgbtRed +
                                   copy[height - 1][width - 2].rgbtRed +
                                   copy[height - 2][width - 1].rgbtRed +
                                   copy[height - 2][width - 2].rgbtRed) /
                          4);
                image[height - 1][width - 1].rgbtGreen =
                    round((float) (copy[height - 1][width - 1].rgbtGreen +
                                   copy[height - 1][width - 2].rgbtGreen +
                                   copy[height - 2][width - 1].rgbtGreen +
                                   copy[height - 2][width - 2].rgbtGreen) /
                          4);
                image[height - 1][width - 1].rgbtBlue =
                    round((float) (copy[height - 1][width - 1].rgbtBlue +
                                   copy[height - 1][width - 2].rgbtBlue +
                                   copy[height - 2][width - 1].rgbtBlue +
                                   copy[height - 2][width - 2].rgbtBlue) /
                          4);
            }
            if (i > 0 && j == 0 && i < height - 1)
            {
                image[i][0].rgbtRed = round(
                    (float) (copy[i][0].rgbtRed + copy[i + 1][0].rgbtRed + copy[i - 1][0].rgbtRed +
                             copy[i][1].rgbtRed + copy[i + 1][1].rgbtRed + copy[i - 1][1].rgbtRed) /
                    6);
                image[i][0].rgbtGreen =
                    round((float) (copy[i][0].rgbtGreen + copy[i + 1][0].rgbtGreen +
                                   copy[i - 1][0].rgbtGreen + copy[i][1].rgbtGreen +
                                   copy[i + 1][1].rgbtGreen + copy[i - 1][1].rgbtGreen) /
                          6);
                image[i][0].rgbtBlue =
                    round((float) (copy[i][0].rgbtBlue + copy[i + 1][0].rgbtBlue +
                                   copy[i - 1][0].rgbtBlue + copy[i][1].rgbtBlue +
                                   copy[i + 1][1].rgbtBlue + copy[i - 1][1].rgbtBlue) /
                          6);
            }
            if (j > 0 && i == 0 && j < width - 1)
            {
                image[0][j].rgbtRed = round(
                    (float) (copy[0][j].rgbtRed + copy[0][j - 1].rgbtRed + copy[0][j + 1].rgbtRed +
                             copy[1][j].rgbtRed + copy[1][j + 1].rgbtRed + copy[1][j - 1].rgbtRed) /
                    6);
                image[0][j].rgbtGreen =
                    round((float) (copy[0][j].rgbtGreen + copy[0][j - 1].rgbtGreen +
                                   copy[0][j + 1].rgbtGreen + copy[1][j].rgbtGreen +
                                   copy[1][j + 1].rgbtGreen + copy[1][j - 1].rgbtGreen) /
                          6);
                image[0][j].rgbtBlue =
                    round((float) (copy[0][j].rgbtBlue + copy[0][j - 1].rgbtBlue +
                                   copy[0][j + 1].rgbtBlue + copy[1][j].rgbtBlue +
                                   copy[1][j + 1].rgbtBlue + copy[1][j - 1].rgbtBlue) /
                          6);
            }
            if (i > 0 && j == width - 1 && i < height - 1)
            {
                image[i][width - 1].rgbtRed = round(
                    (float) (copy[i][width - 1].rgbtRed + copy[i + 1][width - 1].rgbtRed +
                             copy[i - 1][width - 1].rgbtRed + copy[i][width - 2].rgbtRed +
                             copy[i + 1][width - 2].rgbtRed + copy[i - 1][width - 2].rgbtRed) /
                    6);
                image[i][width - 1].rgbtGreen = round(
                    (float) (copy[i][width - 1].rgbtGreen + copy[i + 1][width - 1].rgbtGreen +
                             copy[i - 1][width - 1].rgbtGreen + copy[i][width - 2].rgbtGreen +
                             copy[i + 1][width - 2].rgbtGreen + copy[i - 1][width - 2].rgbtGreen) /
                    6);
                image[i][width - 1].rgbtBlue = round(
                    (float) (copy[i][width - 1].rgbtBlue + copy[i + 1][width - 1].rgbtBlue +
                             copy[i - 1][width - 1].rgbtBlue + copy[i][width - 2].rgbtBlue +
                             copy[i + 1][width - 2].rgbtBlue + copy[i - 1][width - 2].rgbtBlue) /
                    6);
            }
            if (j > 0 && i == height - 1 && j < width - 1)
            {
                image[height - 1][j].rgbtRed = round(
                    (float) (copy[height - 1][j].rgbtRed + copy[height - 1][j - 1].rgbtRed +
                             copy[height - 1][j + 1].rgbtRed + copy[height - 2][j].rgbtRed +
                             copy[height - 2][j + 1].rgbtRed + copy[height - 2][j - 1].rgbtRed) /
                    6);
                image[height - 1][j].rgbtGreen = round(
                    (float) (copy[height - 1][j].rgbtGreen + copy[height - 1][j - 1].rgbtGreen +
                             copy[height - 1][j + 1].rgbtGreen + copy[height - 2][j].rgbtGreen +
                             copy[height - 2][j + 1].rgbtGreen +
                             copy[height - 2][j - 1].rgbtGreen) /
                    6);
                image[height - 1][j].rgbtBlue = round(
                    (float) (copy[height - 1][j].rgbtBlue + copy[height - 1][j - 1].rgbtBlue +
                             copy[height - 1][j + 1].rgbtBlue + copy[height - 2][j].rgbtBlue +
                             copy[height - 2][j + 1].rgbtBlue + copy[height - 2][j - 1].rgbtBlue) /
                    6);
            }
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtRed = round(
                    (float) (copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j].rgbtRed +
                             copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed +
                             copy[i + 1][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                             copy[i + 1][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed) /
                    9);
                image[i][j].rgbtGreen =
                    round((float) (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen +
                                   copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                   copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                   copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen +
                                   copy[i - 1][j + 1].rgbtGreen) /
                          9);
                image[i][j].rgbtBlue =
                    round((float) (copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue +
                                   copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                   copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
                                   copy[i - 1][j - 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue +
                                   copy[i - 1][j + 1].rgbtBlue) /
                          9);
            }
        }
    }
    return;
}
