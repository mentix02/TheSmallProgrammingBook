#include <string>
#include <iostream>

int len(const char *str) {
	unsigned int i = 0;
	while (str[i++] != '\0');
	return i - 1;
}

int main() {
	std::string name;
	std::cout << len(name.c_str()) << std::endl;
	return 0;
}
