#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"

/**
 * {
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;



***/

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

/**
    g.originalBoard = (int *)malloc(9 * 9 * sizeof(int));

    int *originalBoard = malloc(sizeof(g.board));

    memcpy(originalBoard, g.board, sizeof(g.board));

    RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;

            k--;

*/


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
    int lin, col, tot_lin, tot_col;
    int total_times = 0;
    RGBTRIPLE temp_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tot_lin = i;
            tot_col = j;
            lin = i;
            col = j;


            //verifica se linha começa na borda
            if (i <= 0)
                lin = i;

            //verifica se coluna começa na borda
            if (j <= 0)
                col = j;

            //verifica se linha termina na borda
            if (i < height)
                tot_lin++;

            //verifica se coluna termina na borda
            if (j < width)
                tot_col++;

            int col_aux = col;


            // faz um loop para cada pixel somando todos os valores em volta dele
            for (; lin <= tot_lin; lin++)
            {

                for (col = col_aux; col <= tot_col; col++)
                {
                    temp_red = temp_red + image[lin][col].rgbtRed;
                    temp_green += image[lin][col].rgbtGreen;
                    temp_blue += image[lin][col].rgbtBlue;

                    total_times++;
                }
            }

            image[i][j].rgbtBlue = round(temp_blue / (float)total_times);
            image[i][j].rgbtGreen = round(temp_green / (float)total_times);
            image[i][j].rgbtRed = round(temp_red / (float)total_times);

        }
    }

    //image = temp_image;

    return;
}
