#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("How tall will the pyramid be? Please choose between 1 and 8\n");
    int row = 0;
    int col = 0;
    int hash = 0;
    int hashcount = 1;
    int hashright = 0;
    if (height < 1 || height > 8)
    {
        do 
        {
            height = get_int("Please choose between 1 and 8\n");
        }
        while (height < 1 || height > 8);
    }
    //printf("Altura: %i\n", height);

    col = height - 1;
    while (col >= 0)
    {
        for (row = col; row > 0 ; row--)
        {
            printf(" ");            
        }

        for (hash = 0; hash < hashcount; hash++)
        {
            printf("#");
        }

        printf(" ");

        for (hashright = hashcount - 1; hashright >= 0; hashright--)
        {
            printf("#");
        }

        printf("\n\n");
        hashcount++;
        col--;
    }
}
