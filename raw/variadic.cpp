#include <iostream>

template <typename... T>
auto adder(T... args) {
	return (... + args);
}

int main() {
	auto t = adder(3, 4, 2, 6, 1);
	std::cout << t << std::endl;
	return 0;
}
