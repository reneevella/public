
height = int(input("How tall will the pyramid be? Please choose between 1 and 8\n"))

col = 0
hashcount = 1


while height < 1 or height > 8:

    height = int(input("Please choose between 1 and 8\n"))


col = height - 1

while col > 0:

    print(" " * col, end="")

    print("#" * hashcount, end="")

    print("  ", end="")

    print("#" * hashcount, end="")

    print("")

    hashcount += 1

    col -= 1