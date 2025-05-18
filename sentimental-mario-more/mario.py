from cs50 import get_int
height = get_int("Height: ")
while True:
    if height >= 1 and height != 9:
        break
    else:
        height = get_int("Height: ")
        continue
for i in range(height):
    for j in range(height-1-i):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print("  ", end="")
    for l in range(i+1):
        print("#", end="")
    print()
