#include <iostream>

typedef unsigned long long ull;

ull factorial(const unsigned int n) {
	if (n < 2) {
		return (ull) 1;
	} else {
		ull total = 1;
		for (ull i = 2; i <= n; ++i) {
			total *= i;
		}
		return total;
	}
}

int main() {
	unsigned int n = 10;
	auto f = factorial(n);
	std::cout << n << "! = " << f << std::endl;
	return 0;
}
