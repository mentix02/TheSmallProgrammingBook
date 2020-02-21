def factorial(n):
    total = 1
    for i in range(1, n+1):
        total *= i
    return total

if __name__ == '__main__':
    f = factorial(10)
    print(f)
