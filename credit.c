#include <cs50.h>
#include <stdio.h>

string flag = "INVALID";

int contardigitos, digitos, restosum = 0;
long cardnumber;

int main(void)
{
    cardnumber = get_long("Enter your cardnumber:\n");   
    //printf("\n\ndigitos: %i\nContarDigitos: %i\nCardnumber: %li\n", digitos,contardigitos,cardnumber);

    restosum = cardnumber%10;
    cardnumber = cardnumber/10;

    do
    {   
        if ( ((cardnumber % 10) * 2) >= 10)
        {
            contardigitos = contardigitos + (((cardnumber % 10) * 2) - 9);
            cardnumber = cardnumber/10;
            digitos++;
        }
        else
        {
            contardigitos = contardigitos + (cardnumber % 10) * 2;
            cardnumber = cardnumber/10;
            digitos++; 
        }

        restosum = cardnumber%10 + restosum;
        cardnumber = cardnumber/10;
        digitos++;

        if ((cardnumber <= 37 && cardnumber >= 34) || (cardnumber <= 370 && cardnumber >= 340))
        {
            flag = "AMEX";
        }
 
        if ((cardnumber <= 55 && cardnumber >= 51) || (cardnumber <= 550 && cardnumber >= 510))
        {
            flag = "MASTERCARD";
        }

        if ((cardnumber <= 49 && cardnumber >= 40) || (cardnumber <= 490 && cardnumber >= 400))
        {
            flag = "VISA";
        }
    
    }while (cardnumber>=1);

    cardnumber = restosum + contardigitos;

    if ((cardnumber%10) != 0 )
    {
        flag = "INVALID";
    }

    //printf("Digitos: %i\nContarDigitos: %i\nRestosum: %i\nCardnumber: %li\nFlag: %s\n\n\n", digitos,contardigitos, restosum, cardnumber,flag);
    printf("%s\n", flag);
}
