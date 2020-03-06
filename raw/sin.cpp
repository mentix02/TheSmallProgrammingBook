#include <iostream>

float sin(float x) {
  float power, result = 0;
  int factorial, sign = -1;
  for (unsigned n = 1; n <= 10; n += 2) {
    power = 1;                          // Reset values for new fraction.
    factorial = 1;
    for (unsigned j = 1; j <= n; ++j) { // Compute factorial as well as pow(x, n).
      power *= x;
      factorial *= j;
    }
    sign *= -1;                         // Change sign;
    result += sign * power / factorial;
  }
  return result;
}

int main() {
  std::cout << sin(0.42) << std::endl;
  return 0;
}
