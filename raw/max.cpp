#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
auto c_max(std::initializer_list<T> l) {
	if (l.size() == 0)
		throw std::invalid_argument("Empty list provided.");
	auto m = *l.begin();
	for (auto item : l) {
		if (m < item) m = item;
	}
	return m;
}

template <typename T>
auto c_max(std::vector<T> l) {
	if (l.size() == 0)
		throw std::invalid_argument("Empty list provided.");
	auto m = *l.begin();
	for (auto item : l) {
		if (m < item) m = item;
	}
	return m;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <numbers>\n";
		return -1;
	}
	std::vector<int> v(argc - 1);
	for (int arg = 1; arg < argc; ++arg)
		v.push_back(atoi(argv[arg]));
	std::cout << c_max(v) << std::endl;

	return 0;
}
