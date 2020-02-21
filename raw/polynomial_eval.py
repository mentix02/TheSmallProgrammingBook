from math import factorial as ff

def factorial(n):
    if n < 2:
        return 1
    else:
        return ff(n)

def nCr(n, r):
    return factorial(n) / (factorial(n-r) * factorial(r))

def value_at(l, n):
    total = 0
    for i, num in zip(reversed(range(0, len(l))), l):
        total += num * nCr(n, i)
    return total

def aCb(a, b):
    numerator = 1
    for i in range(0, b+2):
        numerator *= a - i
    return numerator / ff(b)

def cvalue_at(poly_spec, x):
    total = 0
    r = reversed(range(0, len(poly_spec)))
    for i, num in zip(r, poly_spec):
        total += num * aCb(x, i)
    return total


if __name__ == '__main__':
    n = 2
    l = [1, 2, 7, 0, 5]
    print(cvalue_at(l, n))
