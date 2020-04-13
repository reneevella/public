#include <cs50.h>
#include <stdio.h>
#include <string.h>

string flag = "INVALID";

int contardigitos, digitos, restosum = 0;
long cardnumber;

int main(void)
{
    cardnumber = get_long("Enter your cardnumber:\n");   
    //printf("\n\ndigitos: %i\nContarDigitos: %i\nCardnumber: %li\n", digitos,contardigitos,cardnumber);

    restosum = cardnumber % 10;
    cardnumber = cardnumber / 10;

    do
    {   
        if (((cardnumber % 10) * 2) >= 10)
        {
            contardigitos = contardigitos + (((cardnumber % 10) * 2) - 9);
            cardnumber = cardnumber / 10;
            digitos++;
        }
        else
        {
            contardigitos = contardigitos + (cardnumber % 10) * 2;
            cardnumber = cardnumber / 10;
            digitos++; 
        }

        restosum = cardnumber % 10 + restosum;
        cardnumber = cardnumber / 10;
        digitos++;

        if ((cardnumber == 37 || cardnumber == 34) || ((cardnumber <= 379 && cardnumber >= 370) || (cardnumber >= 340 
                && cardnumber <= 349))) 
        {
            flag = "a"; //AMEX
            digitos++;
        }
 
        if ((cardnumber <= 55 && cardnumber >= 51) || (cardnumber <= 559 && cardnumber >= 510))
        {
            flag = "m"; //MASTER
        }

        if ((cardnumber <= 49 && cardnumber >= 40) || (cardnumber <= 499 && cardnumber >= 400))
        {
            flag = "v";
        }    
    }
    
    while (cardnumber >= 1);

    cardnumber = restosum + contardigitos;

    if ((cardnumber % 10) != 0)
    {
        flag = "INVALID";
    }

    if ((strcmp(flag, "a") == 0) && digitos == 15) 
    {
        flag = "AMEX";
    }
    else if ((strcmp(flag, "m") == 0) && digitos == 16)
    {
        flag = "MASTERCARD"; 
    }
    else if ((strcmp(flag, "v") == 0) && (digitos == 13 || digitos == 16))
    {
        flag = "VISA";
    }
    else 
    {
        flag = "INVALID";
    }

    // printf("Digitos: %i\nContarDigitos: %i\nRestosum: %i\nCardnumber: %li\nFlag: %s\n\n\n", digitos,contardigitos, restosum, cardnumber,flag);
    printf("%s\n", flag);
}
