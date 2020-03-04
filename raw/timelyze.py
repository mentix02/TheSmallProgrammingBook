from time import time
from typing import Callable, Tuple, Any


def timelyze(f: Callable, iterations: int = 20000, args: Tuple[Any] = None):

	# Start time.
	t1 = time()

	if args:
		for _ in range(iterations):
			f(*args)
	else:
		for _ in range(iterations):
			f()

	# End time.
	t2 = time()

	# Compute necessary numbers.
	time_taken = t2 - t1
	avg_time = time_taken / iterations

	# Round values upto 3 decimal places.
	round_time_taken = round(time_taken, 3)
	round_avg_time = round(avg_time, 3)

	result = f'Took {round_time_taken} seconds with {round_avg_time} on average to run {f.__name__}.'

	data = {
		'result': result,
		'avg_time': avg_time,
		'time_taken': time_taken,
		'round_avg_time': round_avg_time,
		'round_time_taken': round_time_taken,
	}

	return data
