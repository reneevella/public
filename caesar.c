#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int k = atoi(argv[1]);
    char c = 0;

    for (int i = 0, n = strlen(argv[1]); i < n; i++) // verifica se cada caractere da posição 1 é valida e se não tem mais de 2 variaveis no vetor
    {
        if (!isalnum(argv[1][i]) || isalpha(argv[1][i]) || argc > 2 || argc < 1)
        {
            printf("Usage: ./caesar key ");
            return 1;
        }
    }

    string plaintext[1];
    plaintext[0] = get_string("plaintext: ");
    printf("ciphertext: ");


    for (int i = 0, n = strlen(plaintext[0]); i < n; i++)
    {
        c = (plaintext[0][i]);
        char *p;
        p = &c;

        if (isalpha(c)) //se for letra, faz o calculo
        {
            c = plaintext[0][i];

            if (islower(c))
            {
                c = ((c - 97) + k) % 26;
                printf("%c", c + 97);
            }
            else
            {
                c = ((c - 65) + k) % 26;
                printf("%c", c + 65);
            }
        }

        else //(!isalpha(plaintext[0][i])) imprime caracteres nao alfabeticos
        {
            printf("%c", plaintext[0][i]);
        }
    }
    printf("\n");
    return 0;
}



