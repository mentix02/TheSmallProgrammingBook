class Calculator(object):

    def _assign_precedence(self, operation):
        if operation == '*' or operation == '/': return 2
        elif operation == '+' or operation == '-': return 1
        else: return 0

    def _perform_operation(self, n1, n2, operation):
        if operation == '+':
            return n1 + n2
        elif operation == '-':
            return n1 - n2
        elif operation == '*':
            return n1 * n2
        elif operation == '/':
            return n1 / n2

    def _parse_number(self, expression, start):
        index = start
        number = 0.0
        decimal_place = -1

        while index < len(expression) and (expression[index].isdigit() or expression[index] == '.'):
            if expression[index] != '.':
                number = (number * 10) + int(expression[index])
                index += 1
            else:
                decimal_place = index
                index += 1
        if decimal_place != -1:
            number = number / (10 ** (index - decimal_place - 1))

        return number, index

    def evaluate(self, expression):
        index            = 0
        values_stack     = []
        operations_stack = []

        while index < len(expression):

            # Ignore whitespace.
            if expression[index] == ' ':
                index += 1
                continue

            # Start an embedded expression by submitting it to the operations stack.
            elif expression[index] == '(':
                operations_stack.append(expression[index])

            # Start storing a number to the values stack until the character at the
            # next, incremented index is not a digit anymore.
            elif expression[index].isdigit() or expression[index] == '.':
                number, index = self._parse_number(expression, index)
                print(number)
                values_stack.append(number)

            # Stop the nested expression and evaluate start 
            elif expression[index] == ')':
                while len(operations_stack) != 0 and operations_stack[-1] != '(':
                    b = values_stack.pop()
                    a = values_stack.pop()
                    operation = operations_stack.pop()

                    result = self._perform_operation(a, b, operation)

                    values_stack.append(result)
                # Remove the opening parenthesis.
                operations_stack.pop()

            # Only case remaining is if the current index at 'expression' contains an operator.
            else:
                while len(operations_stack) != 0 and self._assign_precedence(operations_stack[-1]) >= self._assign_precedence(expression[index]):
                    b = values_stack.pop()
                    a = values_stack.pop()
                    operation = operations_stack.pop()

                    result = self._perform_operation(a, b, operation)

                    values_stack.append(result)

                # Push for later evaluation.
                operations_stack.append(expression[index])

            index += 1

        # Only remaining operators need to be evaluated.
        while len(operations_stack) != 0:
            b = values_stack.pop()
            a = values_stack.pop()
            operation = operations_stack.pop()

            result = self._perform_operation(a, b, operation)
            values_stack.append(result)

        # Value at the top of the stack is the final required value.
        return values_stack[-1]


if __name__ == '__main__':
    c = Calculator()
    print(c.evaluate('8/16'))
