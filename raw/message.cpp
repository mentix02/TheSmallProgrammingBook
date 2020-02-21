#include <mutex>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

void WriteToFile(const std::string& message) {
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);

	std::ofstream file("message.txt");
	if (!file.is_open()) {
		throw std::runtime_error("unable to open file");
	}
	file << message << std::endl;
}

int main() {
	std::string s;
	std::cout << "Enter a message : ";
	std::getline(std::cin, s);
	WriteToFile(s);
	return 0;
}
