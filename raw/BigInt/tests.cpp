#include "BigInt.h"
#include <cassert>
#include <iostream>

int main() {
	BigInt b1("3415");
	BigInt b2("4515");
	auto b3 = b1 + b2;
	assert(b1 + b2 == b3);
	return 0;
}
