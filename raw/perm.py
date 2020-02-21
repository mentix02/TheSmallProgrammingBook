from itertools import product

def all_repeat(s, r):
    chars = list(s)
    for c in product(chars, repeat=r):
        yield c

counter = 0

for index, i in enumerate(all_repeat("0123456789", 7)):
    if i.count("6") >= 5:
        print('calculating...', ''.join(i), f' |  counter : {counter}', f' |  checked : {index}', end='\r')
        counter += 1

print('calculating...', ''.join(i), f' |  counter : {counter}')
