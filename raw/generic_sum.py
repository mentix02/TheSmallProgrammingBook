from typing import Sequence, Any


class Attack(object):
    """
    Custom class to overload the + operator of.
    """

    def __init__(self, damage: int = 100) -> None:
        self.damage = damage

    def __add__(self, attack):
        return Attack(self.damage + attack.damage)

    def __repr__(self):
        return '<Attack: %s>' % self.damage


def sum(l: Sequence[Any]) -> Any:
    if len(l) == 0:
        return 0
    else:
        total = l[0]
        for i in range(1, len(l)):
            total += l[i]
        return total


if __name__ == '__main__':
    l1 = [Attack(37), Attack(43), Attack(95), Attack(21)]
    l2 = ['ab', 'cd', 'ef', 'gh', 'ij', 'kl', 'mn', 'op', 'qr', 'st', 'uv', 'wx', 'yz']
    total1, total2 = sum(l1), sum(l2)
    print(total1, total2, sep='\n')
