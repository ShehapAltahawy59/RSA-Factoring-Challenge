import sys

def factorize(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return 1, n

def main():
    filename = sys.argv[1]
    with open(filename, 'r') as file:
        numbers = [int(line.strip()) for line in file]

    for number in numbers:
        p, q = factorize(number)
        print(f'{number}={p}*{q}')

if __name__ == "__main__":
    main()

