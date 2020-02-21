import time


def countSetBits(n):
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count


def count_set_bits(n):
    total = 0
    while n:
        n &= n - 1
        total += 1
    return total


def count_bits(n):
    return bin(n)[2:].count('1')


def timeit(f):
    t1 = time.time()
    for i in range(1, 4000000):
        f(i)
    t2 = time.time()
    print(f'{f.__name__} took {round(t2-t1, 7)} seconds.')


if __name__ == '__main__':
    timeit(count_bits)
    timeit(countSetBits)
    timeit(count_set_bits)
