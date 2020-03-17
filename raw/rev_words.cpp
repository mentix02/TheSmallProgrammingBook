#include <vector>
#include <iostream>

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
      r.push_back(word);
      word = "";
    }
    index++;
  }
  return r;
}

std::string join(std::vector<std::string> v) {
  std::string builder = "";
  for (unsigned int word = v.size() - 1; word != 0; --word) {
    builder += v[word] + " ";
  }
  return builder + v[0];
}

int main() {
  auto v = join(split_reverse("a good   example"));
  std::cout << v << std::endl;
  return 0;
}
