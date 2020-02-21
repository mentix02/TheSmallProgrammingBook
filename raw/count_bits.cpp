#include <iostream>

unsigned long long count_bits(unsigned long long n) {
	unsigned long long total = 0;
	while (n > 0) {
		n &= n - 1;
		total += 1;
	}
	return total;
}

int main() {
	std::cout << count_bits(5) << std::endl;
	std::cout << count_bits(100) << std::endl;
	return 0;
}
