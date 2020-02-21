"""
This file attempts to demonstrate left shifting for numbers by 1.
"""

def twos_multiple_generator(n):
    num = 1
    while num <= n:
        num <<= 1
        yield num

nums = list(twos_multiple_generator(64))
print(nums)
