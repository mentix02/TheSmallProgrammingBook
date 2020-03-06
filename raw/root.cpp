#include <cmath>
#include <stdlib.h>
#include <iostream>

double sqrt(int n) {
	double x0 = 1;
	while ( (x0 * x0) - 1 <= n )
		++x0;
	for (unsigned _ = 0; _ < 10; ++_)
		x0 -= (std::pow(x0, 2) - n) / (x0 * 2);
	return x0;
}

int main(int argc, char *argv[]) {
	if (argc == 1) return -1;
	int n = atoi(argv[1]);
	std::cout << sqrt(n) << std::endl;
	return 0;
}
