from numpy import array
from typing import Iterable

class Vector(object):

    def __init__(self, iterable):
        self.data = list(iterable)

    def __repr__(self):
        return "Vector(" + repr(self.data) + ")"

    def __mul__(self, obj):
        if isinstance(obj, int):
            return Vector(map(lambda x : x * obj, self.data))

    def __add__(self, obj):
        if isinstance(obj, Iterable):
            return _iterative_op(obj, '+')
        elif isinstance(obj, int):
            d = []
            for item in self.data:
                d.append(item + obj)
            return Vector(d)
        else:
            raise ValueError("Vector does not support hetrogenous addition.")

    def __sub__(self, obj):
        if isinstance(obj, Iterable):
            return _iterative_op(obj, '-')
        elif isinstance(obj, int):
            d = []
            for item in self.data:
                d.append(item - obj)
            return Vector(d)
        else:
            raise ValueError("Vector does not support hetrogenous subtraction.")

    def __getitem__(self, index):
        return self.data[index]

    def __eq__(self, obj):
        if not isinstance(obj, Iterable):
            return False
        else:
            if len(self) != len(obj):
                return False
            else:
                for index in range(len(self)):
                    if self[index] != obj[index]:
                        return False
                else:
                    return True

    def __len__(self):
        return len(self.data)

    def __iter__(self):
        for item in self.data:
            yield item

    def _op(self, x, y, op):
        return eval(f'{x} {op} {y}')

    def _iterative_op(self, v, op):
        arr = []
        for x, y in zip(self.data, v.data):
            arr.append(self._op(x, y, op))
        return Vector(arr)


if __name__ == '__main__':
    v1 = Vector([1, 2, 3, 4])
    n1 = array([1, 2, 3, 4])
