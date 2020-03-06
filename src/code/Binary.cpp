#include <cmath>
#include <utility>
#include <iostream>

long NOT(const long n) {
  return -(n + 1);
}

long AND(const int x, const int y) {
  long result = 0;
  int upper = std::floor(std::log2(x)) + 1;
  for (unsigned n = 0; n < upper; ++n) {
    long two_power_n = std::pow(2, n);
    result += two_power_n * ( (long)(std::floor(x / two_power_n)) % 2 ) * ( (long)(std::floor(y / two_power_n)) % 2 );
  }
  return result;
}

long OR(int x, int y) {
  long result = 0;
  if (y > x)
    std::swap(x, y);
  int upper = std::floor(std::log2(x)) + 1;
  for (unsigned n = 0; n < upper; ++n) {
    long two_power_n = std::pow(2, n);
    long x_2n_mod_2 = (long)(std::floor(x / two_power_n)) % 2;
    long y_2n_mod_2 = (long)(std::floor(y / two_power_n)) % 2;
    auto prod = x_2n_mod_2 * y_2n_mod_2;
    result += two_power_n * (( x_2n_mod_2 + y_2n_mod_2 + prod ) % 2);
  }
  return result;
}

long XOR(const int x, const int y) {
  long result = 0;
  int upper = std::floor(std::log2(x)) + 1;
  for (unsigned n = 0; n < upper; ++n) {
    long two_power_n = std::pow(2, n);
    long x_2n = (long)(std::floor(x / two_power_n));
    long y_2n = (long)(std::floor(y / two_power_n));
    result += two_power_n * (long)((x_2n + y_2n) % 2);
  }
  return result;
}
