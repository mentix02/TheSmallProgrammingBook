from pprint import pprint
from timelyze import timelyze


def naive_even(n: int):
    return n % 2 == 0


def run_naive_even(iterations: int):
    for i in range(iterations):
        naive_even(i)


def faster_even(n: int):
    return n & 1 == 0


def run_faster_even(n: int):
    for i in range(n):
        faster_even(i)


if __name__ == '__main__':
    pprint(timelyze(run_naive_even, args=(5000,)))
    pprint(timelyze(run_faster_even, args=(5000,)))
