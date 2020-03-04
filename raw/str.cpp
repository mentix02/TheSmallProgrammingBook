#include <string.h>
#include <iostream>

#define INITIAL_LENGTH 20

class str {
	private:
		char *s;
		int len, capacity;
	public:

		str();
		~str();
		str(const char* ps);

		bool append(char c);
		bool append(const char* ps);

		char* c_str() {return s;}

		str operator + (const str ps);
		str operator + (const char* ps);
		str operator = (const char* ps);

		friend std::ostream&operator << (std::ostream& os, const BigInt& bi);

};

bool str::append(char c) {
	char *temp;
	if (len >= capacity) {
		temp = new char[2*capacity];
		for (int i = 0; i < capacity; ++i)
			temp[i] = s[i];
		capacity = capacity << 1;
		delete [] s;
		s = temp;
	}
	s[len] = c;
	len++;
	return true;
}

bool str::append(const char *ps) {
	for (unsigned i = 0; i < strlen(ps); ++i)
		append(ps[i]);
	return true;
}

str::str(const char* pc) {
	len = strlen(pc);
	capacity = len * 2;
	s = new char[capacity];
	strcpy(s, pc);
}

str::str() {
	capacity = INITIAL_LENGTH;
	s = new char[capacity];
	len = 0;
}

str::~str() {
	if (s) delete [] s;
}

std::ostream& operator << (std::ostream& os, const BigInt& bi) {
    os << bi.num;
    return os;
}

int main() {
	str s1("abcd");
	std::cout << s1 << std::endl;
	s1.append("efgh");
	std::cout << s1 << std::endl;
	return 0;
}
