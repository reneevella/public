from sys import argv, exit
import csv
import sys


if len(argv)!=3:
    print ("Usage: python dna.py data.csv sequence.txt")

else:
    csvpath = argv[1]

    #open csv file
    with open(csvpath) as csvfile:
        data_file = csv.reader(csvfile)

        row_aux = next(data_file)

    #open text file
    with open(sys.argv[2], 'r') as file:
        sequence = file.read()

        #contador para guardar o maior numero de uma sequencia
        counter = []

        #passa por cada elemento da sequencia para conta-las
        for i in range(1, len(row_aux)):
            count_str = 0

            for c in sequence:
                n = 1

                #se achar alguma sequencia no arquivo, continua procurando até acabar
                while row_aux[i]*n in sequence:
                    n += 1

                if (n - 1) > count_str:
                    count_str = n - 1

            # add the highest number of occurance into list counter
            counter.append(count_str)



        # condition to check if go through all text file and have not found object
        found = False
        for row in data_file:
            for c in range(len(counter)):

                # if any element or csv row does not match the list counter, skip to next row
                if int(row[c+1]) != int(counter[c]):
                    break

                # if we reach the last element and loop is still not broken, this means this is the row required
                elif c == (len(counter)-1):
                    print(row[0])
                    found = True
                    break

        # if go through and have not found anything
        if found == False:
            print("No match")