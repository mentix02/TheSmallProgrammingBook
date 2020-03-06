#include <iostream>

long NOT(const long n) {
  return -(n + 1);
}

double sqrt(int n) {
  double x0 = 1;
  while (std::pow(x0, 2) - 1 <= n)
    ++x0;
  for (unsigned _ = 0; _ < 10; ++_)
    x0 -= (std::pow(x0, 2) - n) / (x0 * 2);
  return x0;
}

#define ACCURACY 10

auto sin(const float x) {
  float power, result = 0;
  int factorial, sign = 1;
  for (unsigned n = 1; n <= ACCURACY; n += 2) {
    power = 1;
    factorial = 1;
    for (unsigned j = 1; j <= n; ++j) {
      power *= x;
      factorial *= j;
    }
    sign *= -1;
    result += sign * power / factorial;
  }
  return result;
}
