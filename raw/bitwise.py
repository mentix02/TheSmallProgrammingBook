from math import log2, floor

def NOT(x):
    return -(x + 1)

def AND(x, y):
    result = 0
    upper = floor(log2(x)) + 1
    for n in range(upper):
        result += (2 ** n) * (floor(x/2**n) % 2) * (floor(y/2**n) % 2)
    return result


def OR(x, y):
    result = 0
    if y > x:
        x, y = y, x
    upper = floor(log2(x)) + 1
    for n in range(upper):
        x_2n_mod_2 = floor(x / 2**n) % 2
        y_2n_mod_2 = floor(y / 2**n) % 2
        prod = x_2n_mod_2 * y_2n_mod_2
        result += (2 ** n) * (( x_2n_mod_2 + y_2n_mod_2 + prod ) % 2)
    return result

assert OR(15914, 345) == 15914 | 345
