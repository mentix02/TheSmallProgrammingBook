#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "BigInt.hpp"

BigInt::BigInt() {
	num = "0";
}

bool BigInt::operator < (BigInt const &obj) {

	if (num.length() != obj.num.length()) return false;

	for (unsigned i = 0; i < num.length(); i++) {
		if (num[i] < obj.num[i]) return true;
		else if (num[i] > obj.num[i]) return false;
	}

	return false;

}

bool BigInt::operator == (BigInt const &obj) {
	if (num.length() != obj.num.length()) return false;
	for (unsigned i = 0; i < num.length(); i++) {
		if (num[i] != obj.num[i]) return false;
	}
	return true;
}

BigInt BigInt::operator + (BigInt const &obj) {

	std::string s1 = num, s2 = obj.num;

	if (s1.length() > s2.length()) {
		std::swap(s1, s2);
	}

	std::string result;
	int n1 = s1.length(), n2 = s2.length();
	int carry = 0;
	int diff = n2 - n1;

	for (int i = n1 - 1; i >= 0; --i) {
		int sum = (s1[i] - '0') + (s2[i + diff] - '0') + carry;
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = n2 - n1 - 1; i >= 0; --i) {
		int sum = (s2[i] - '0') + carry;
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) result.push_back(carry + '0');

	reverse(result.begin(), result.end());
	BigInt r(result.c_str());
	return r;
}

template <typename T>
BigInt::BigInt(const T& n) {
	num = std::to_string(n);
}

BigInt::BigInt(const std::string s) {
	BigInt(s.c_str());
}

BigInt::BigInt(const char* s) {
	for (size_t i = 0; i < strlen(s); ++i)
		if (isdigit(s[i]))
			num += s[i];
		else
			throw std::invalid_argument("Received non integral value.");
}

std::ostream& operator << (std::ostream& os, const BigInt& bi) {
	os << bi.num;
	return os;
}
