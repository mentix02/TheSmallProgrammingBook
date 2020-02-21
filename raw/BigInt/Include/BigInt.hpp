#ifndef DATABASE_H
#define DATABASE_H

class BigInt {

	private:

		std::string num;

	public:

		BigInt();

		template <typename T>
		BigInt(const T& n);
		BigInt(const char* s);
		BigInt(const std::string s);

		bool operator == (const int num);
		bool operator < (BigInt const &obj);
		bool operator == (BigInt const &obj);
		BigInt operator + (BigInt const &obj);
		bool operator == (const std::string s);
		friend std::ostream& operator<<(std::ostream& os, const BigInt& bi);

};

#endif
