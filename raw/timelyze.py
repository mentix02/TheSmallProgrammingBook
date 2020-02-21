#!/usr/bin/env python3
import time
import typing


def timelyze(f: typing.Callable, iterations: int = 200, args: typing.Tuple[typing.Any] = None) -> typing.Dict[str, typing.Any]:
    """
    A generic function to measure the running time of a function
    over a fixed number of iterations. Returns a dictionary
    containing formatted string that includes total time taken,
    average iteration time, and name of function to run (and all
    other relevant data, such as the arguments of the function).
    """

    # Start time.
    t1 = time.time()

    if args is not None:
        for _ in range(iterations):
            f(*args)
    else:
        for _ in range(iterations):
            f()

    # End time.
    t2 = time.time()

    # Compute necessary numbers.
    time_taken = t2 - t1
    avg_time = time_taken / iterations

    # Round values upto 3 decimal places.
    round_time_taken = round(time_taken, 3)
    round_avg_time = round(avg_time, 3)

    stats = f'Took {round_time_taken} seconds with {round_avg_time} on average'
    if not args:
        result = f'{stats}'
    else:
        result = f'{stats} to run "{args[0].__name__}()".'

    del stats
    data = dict(locals())

    del data['f']
    del data['_']
    del data['t1']
    del data['t2']

    return data


def run_func(f: typing.Callable, iterations: int = 2000, args: typing.Tuple[typing.Any]):
    for i in range(1, iterations):
        f(i)
