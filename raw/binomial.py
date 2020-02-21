from math import factorial


def C(n, r):
    num = factorial(n)
    den = factorial(r) * factorial(n - r)
    return int(num / den)


def extract_terms(expr):
    inner_expr, n = expr.split('^')

    n = int(n)
    inner_expr = inner_expr.strip('()')

    # Extract x's co efficient.
    index = 0
    x_coeff = ''

    while not inner_expr[index].isalpha():
        x_coeff += inner_expr[index]
        index += 1

    if len(x_coeff) == 0:
        x_coeff = 1

    x = inner_expr[index]
    if x_coeff == '-':
        x_coeff = -1
    else:
        x_coeff = int(x_coeff)

    op = inner_expr[index]
    y  = int(inner_expr[index+1:])

    return inner_expr, x_coeff, x, y, n, op

def expand(expr):

    inner_expr, x_coeff, x, y, n, op = extract_terms(expr)

    if n == 0:
        # Expression to the power 0 is 1.
        return '1'
    elif n == 1:
        # Expression to the power 1 is itself.
        return inner_expr
    elif y == 0:
        return f'{x_coeff ** n}{x}^{n}' if x_coeff not in [0, 1] else f'{x}^{n}'
    else:
        c = 0
        b = n
        builder = []

        while b >= 0:
            # nCb = n! / b!(n-b)!
            n_choose_b = C(n, b)

            # Binomial coefficient.
            a = (1 if n_choose_b == 1 else n_choose_b) * (x_coeff ** b)

            # x part raised to the power of b.
            if b != 0:
                if b == 1:
                    x_part = f'{x}'
                else:
                    x_part = f'{x}^{b}'
            else:
                x_part = ''

            y_part = y ** c if c != 0 else 1

            first_part = f'{a*y_part}{x_part}' if a != 1 else x_part

            if not first_part:
                first_part = f'{y**c}'
            if first_part[0] != '-':
                if b != n:
                    builder.append('+' + first_part)
                    c += 1
                    b -= 1
                    continue
            builder.append(first_part)

            c += 1
            b -= 1

        if builder[0].startswith(f'-1{x}'):
            builder[0] = '-' + builder[0][2:]
        return ''.join(builder)


if __name__ == '__main__':
    expr = input('Enter expression : ')
    print(expr, expand(expr), sep=' = ')
