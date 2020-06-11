
userinput = input("How tall will the pyramid be? Please choose between 1 and 8\n")

test = 0
col = 0
hashcount = 1

while test == 0:
    try:
        height = int(userinput)

    except ValueError:
        height = 0

    if height in range(1, 9):
        test = 1

    else:
        userinput = input("Please choose between 1 and 8\n")


col = height - 1

while col >= 0:

    print(" " * col, end="")

    print("#" * hashcount, end="")

    print("  ", end="")

    print("#" * hashcount, end="")

    print("")

    hashcount += 1

    col -= 1