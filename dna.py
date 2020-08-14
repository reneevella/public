from sys import argv, exit
import itertools
import csv
import re


if len(argv) != 3:
    print ("Usage: python dna.py data.csv sequence.txt")
    exit(1)


with open(argv[1],"r") as csv_file:
    csv_readfile = list(csv.reader(csv_file))

    csv_readfile[0].remove("name")

    copy_csv = csv_readfile[0]



with open(argv[2],"r") as txt:
    sequence = txt.read()


valores = []


for n in range(len(copy_csv)):
    maior = 0
    contador = 0
    pos_atual = 0
    anterior = 0


    while pos_atual < len(sequence):

        pos_atual = sequence.find(copy_csv[n], pos_atual)

        if pos_atual == -1:
            contador = 0
            break

        elif anterior == 0 and (pos_atual != -1) :

            contador += 1
            maior = contador
            anterior = pos_atual


        elif (pos_atual != -1) and ((pos_atual - len(copy_csv[n])) == anterior):

            contador += 1
            anterior = pos_atual

            if maior < contador:
                maior = contador


        elif (pos_atual != -1) and ((pos_atual - len(copy_csv[n])) != anterior):
            contador = 1
            anterior = pos_atual

            if maior < contador:
                maior = contador
        pos_atual += 1


    valores.append(maior)


valores = list(map(str, valores))
busca = list(csv_readfile)
busca.pop(0)


for linha in busca:

    if linha[1:] == valores:
        print(f"{linha[0]}")
        break

    elif linha == busca[-1]:
        print("No match")