import pprint
import random
import timelyze


def binary_search(nums, target):
    left, right = 0, len(nums) - 1
    while (left <= right):
        middle = (left + right) / 2
        if nums[middle] == target:
            return middle
        elif middle < left:
            right = middle - 1
        else:
            left = middle + 1
    return -1


def linear_search(nums, target):
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    else:
        return -1


def search(nums, target, s = False):
    return binary_search(nums, target) if s else linear_search(nums, target)


def main():
    nums = list(range(1, 999999+2))
    d1 = timelyze.timelyze(search, 500, args=(nums, random.choice(nums)))
    nums.sort()
    d2 = timelyze.timelyze(search, 500, args=(nums, random.choice(nums), True))
    return [d1, d2]


if __name__ == '__main__':
    d1, d2 = main()
    pprint.pprint(d1)
    pprint.pprint(d2)
