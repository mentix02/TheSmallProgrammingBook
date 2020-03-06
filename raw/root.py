def sqrt(n):
    x0 = 1
    while (x0 * x0) - 1 <= n:
        x0 += 1
    for _ in range(10):
        x0 -= ( (x0**2 - n) / (x0 * 2) )
    return x0


def root(n, p=2):
    x0 = 1
    while (x0 * x0) - 1 <= n:
        x0 += 1
    for _ in range(10):
        x0 -= ( (x0**p - n) / (p * (x0 ** (p-1))) )
    return x0
