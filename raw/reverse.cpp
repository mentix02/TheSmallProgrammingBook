#include <string>
#include <vector>
#include <iostream>

std::string reverse_word(std::string word) {
	std::string rev = "";
	for (int i = word.length() - 1; i >= 0; --i) {
		rev += word[i];
	}
	return rev;
}

std::vector<std::string> split_reverse(std::string words, const char delimeter = ' ') {
	std::string word = "";
	unsigned int index = 0;
	std::vector<std::string> r;
	while (index < words.length()) {
		if (words[index] == delimeter) {
			index++;
			continue;
		} else {
			while (words[index] != delimeter && index < words.length()) {
				word += words[index++];
			}
			r.push_back(reverse_word(word));
			word = "";
		}
		index++;
	}
	return r;
}

std::string join(std::vector<std::string> v) {
	std::string builder = "";
	for (auto word : v) {
		builder += word + " ";
	}
	return builder;
}

int main() {
	std::string words = "The quick brown fox jumps over the lazy dog.";
	std::cout << join(split_reverse(words)) << std::endl;
	std::cout << join(split_reverse("a b c d")) << std::endl;
	return 0;
}
