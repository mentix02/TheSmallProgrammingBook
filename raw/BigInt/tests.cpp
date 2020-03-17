#include "BigInt.hpp"

int main() {
	BigInt b1("3415");
	BigInt b2("4515");
	auto b3 = b1 + b2;
	std::cout << b1 << " + " << b2 << " = " << b3 << std::endl;
	return 0;
}
