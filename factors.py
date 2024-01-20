import sys
import math
import random

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def pollards_rho(n):
    if n % 2 == 0:
        return 2
    x = random.randint(1, n-1)
    y = x
    c = random.randint(1, n-1)
    g = 1
    while g==1:             
        x = ((x * x) % n + c) % n
        y = ((y * y) % n + c) % n
        y = ((y * y) % n + c) % n
        g = gcd(abs(x-y), n)
    return g

def main():
    filename = sys.argv[1]
    with open(filename, 'r') as file:
        numbers = [int(line.strip()) for line in file]

    for number in numbers:
        p = pollards_rho(number)
        q = number // p
        print(f'{number}={p}*{q}')

if __name__ == "__main__":
    main()

