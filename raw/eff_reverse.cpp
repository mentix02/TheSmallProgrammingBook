#include <string>
#include <iostream>
#include <algorithm>

void reverse_word(std::string& s, unsigned int start, unsigned int stop) {
	for (unsigned int i = 0; i < (stop - start) / 2; i++) {
		std::swap(s[i + start], s[stop - i - 1]);
	}
}

void reverse(std::string& words) {
	unsigned int start = 0;
	unsigned int index = 0;
	while (index < words.length()) {
		if (words[index] == ' ') {
			index++;
			continue;
		} else {
			start = index;
			while (words[index] != ' ' && index < words.length()) {
				index++;
			}
			reverse_word(words, start, index);		
		}
		index++;
	}
}

int main() {
	std::string s = "         Hello world! This is a cool function.";
	std::cout << s << std::endl;
	reverse(s);
	std::cout << s << std::endl;
	return 0;
}
