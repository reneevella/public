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
    i = csv_readfile[0]



with open(argv[2],"r") as txt:
    sequence = txt.read()


valores = []


for q in range(len(i)):
    maior = 0
    contador = 0
    pos_atual = 0
    anterior = 0


    while pos_atual < len(sequence):

        # this gives the position at which the sequence is found
        pos_atual = sequence.find(i[q], pos_atual)

        if pos_atual == -1:
            contador = 0
            break

        elif (pos_atual != -1) and anterior == 0:
            contador += 1
            maior = contador
            anterior = pos_atual

        #sequential occurances
        elif (pos_atual != -1) and ((pos_atual - len(i[q])) == anterior):
            counter += 1
            anterior = pos_atual
            if maior < contador:
                maior = contador

        #first found and not at the start of the sequence.
        elif (pos_atual != -1) and ((pos_atual - len(i[q])) != anterior):
            contador = 1
            anterior = pos_atual

            if maior < contador:
                maior = contador
        pos_atual += 1


    #record the largest number of sequencial occurances.
    valores.append(maior)

#the following compares the occurances of each nucliotide to the databases
#update the list to be a list of strings to enable comparison.
valores = list(map(str, valores))

#make a new list to preserve reader
cleaned = list(csv_readfile)
cleaned.pop(0)

#compare valuelist to reader and if found print the name of the person whos DNA has all the occurances to the console/terminal.
for person in cleaned:
    if person[1:] == valores:
        print(f"{person[0]}")
        break
    elif person == cleaned[-1]:
        print("No match")