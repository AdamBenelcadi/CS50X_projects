from cs50 import get_float
import sys


while True:
    change = get_float("Change: ")
    if change > 0:
        break
    else:
        change = get_float("Change: ")

change_in_cent = change*100

A = change_in_cent // 25
if change_in_cent % 25 == 0:
    print(int(A))
    sys.exit()
B = (change_in_cent - A*25) // 10
if (change_in_cent - A*25) % 10 == 0:
    print(int(A+B))
    sys.exit()
C = (change_in_cent - A*25 - B*10) // 5
if (change_in_cent - A*25 - B*10) % 5 == 0:
    print(int(A+B+C))
    sys.exit()
D = (change_in_cent - A*25 - B*10 - C*5)
print(int(A + B + C + D))
