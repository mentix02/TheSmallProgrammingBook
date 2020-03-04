#include <ctime>
#include <utility>
#include <stdlib.h>
#include <iostream>

#define TOTAL 500

bool heads() {
	srand(time(NULL));
	int coin = rand() % 2;

	if (coin == 0) return true;
	else return false;
}

std::pair<bool, int> counter() {
	auto p = std::make_pair(true, 0);
	for (unsigned long i = 0; i < TOTAL; ++i) {
		if (heads()) ++p.second;
	}
	return p;
}

int main() {
	auto p = counter();
	std::cout << 
	std::cout << "Heads : " << p.second << std::endl;
	std::cout << "Tails : " << TOTAL - p.second << std::endl;
	return 0;
}
