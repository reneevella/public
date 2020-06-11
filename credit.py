from cs50 import get_int


flag = "INVALID"

contardigitos = 0
digitos = 0
restosum = 0


cardnumber = get_int("Enter your cardnumber:\n");

# printf("\n\ndigitos: %i\nContarDigitos: %i\nCardnumber: %li\n", digitos,contardigitos,cardnumber);

restosum = cardnumber % 10;
cardnumber = cardnumber / 10;



while cardnumber >= 1:


    if ((cardnumber % 10) * 2) >= 10:

        contardigitos = contardigitos + (((cardnumber % 10) * 2) - 9)
        cardnumber = cardnumber / 10
        digitos += 1

    else:

        contardigitos = contardigitos + (cardnumber % 10) * 2;
        cardnumber = cardnumber / 10;
        digitos += 1

    restosum = cardnumber % 10 + restosum
    cardnumber = cardnumber / 10
    digitos += 1


    if ((cardnumber == 37 or cardnumber == 34) or ((cardnumber <= 379 and cardnumber >= 370) or (cardnumber >= 340 and cardnumber <= 349))):

        flag = "a"
        digitos += 1


    if ((cardnumber <= 55 and cardnumber >= 51) or (cardnumber <= 559 and cardnumber >= 510)):

        flag = "m"


    if ((cardnumber <= 49 and cardnumber >= 40) or (cardnumber <= 499 and cardnumber >= 400)):

        flag = "v"




cardnumber = restosum + contardigitos

if ((cardnumber % 10) != 0):

    flag = "INVALID"


if (flag == "a") and digitos == 15:

    flag = "AMEX"

elif (flag == "m") and digitos == 16:

    flag = "MASTERCARD"

elif (flag == "v") and (digitos == 13 or digitos == 16):

    flag = "VISA"

else:

    flag = "INVALID"


print(" " + flag)


# printf("Digitos: %i\nContarDigitos: %i\nRestosum: %i\nCardnumber: %li\nFlag: %s\n\n\n", digitos,contardigitos, restosum, cardnumber,flag);

