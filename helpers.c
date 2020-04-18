#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int temp = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtRed = temp;
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
            int temp_blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int temp_green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int temp_red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            if (temp_blue > 255)
                temp_blue = 255;

            if (temp_green > 255)
                temp_green = 255;

            if (temp_red > 255)
                temp_red = 255;

            image[i][j].rgbtRed = temp_red;
            image[i][j].rgbtBlue = temp_blue;
            image[i][j].rgbtGreen = temp_green;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE *imgcpy = malloc(width * sizeof(RGBTRIPLE));
    if (NULL == imgcpy)
    {
    // malloc failed
    return;
    }


    for (int i = 0; i < height; i++)
    {
        int k = width - 1;

        // copia conteudo de image para imgcpy

        //memcpy(imgcpy, image, sizeof(width * sizeof(RGBTRIPLE)));

        for (int j = 0; j < width; j++)
        {
            imgcpy[j] = image[i][j];

        }

        for (int j = 0; j < width; j++)
        {
            image[i][j] =  imgcpy[k];
            k--;
        }
    }

    free (imgcpy);

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    int temp_blue = 0, temp_green = 0, temp_red = 0;
    int ii, hh, jj, ww = 0;


                int soma_b = 0;
            int soma_g = 0;
            int soma_r = 0;

            int divisor = 0;

    RGBTRIPLE temp_image[height][width];


    //verifica valor de image, faz a conta, guarda em img-temp
    for (int i = 0; i < height; i++)
    {



        for (int j = 0; j < width; j++)
        {
            ii = i - 1;
            jj = j - 1;

            if (i == 0)
                ii++;

            if (j == 0)
                jj++;

            hh = i;
            ww = j;

            if (hh < height)
                hh++;

            if (ww < width)
                ww++;

            int aux_jj = jj;


            // loop interno para cada pixel
            for (; ii <= hh; ii++)
            {
                for (jj = aux_jj; jj <= ww; jj++)
                {
                    soma_r = soma_r + image[ii][jj].rgbtRed;
                    soma_g = soma_g + image[ii][jj].rgbtGreen;
                    soma_b = soma_b + image[ii][jj].rgbtBlue;
                    divisor ++;
                }
            }
            soma_r = round(soma_r / (float)divisor);
            soma_g = round(soma_g / (float)divisor);
            soma_b = round(soma_b / (float)divisor);

            temp_image[i][j].rgbtRed = soma_r;
            temp_image[i][j].rgbtGreen = soma_g;
            temp_image[i][i].rgbtBlue = soma_b;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp_image[i][j].rgbtGreen;
            image[i][i].rgbtBlue = temp_image[i][i].rgbtBlue;
        }
    }


    return;
}
