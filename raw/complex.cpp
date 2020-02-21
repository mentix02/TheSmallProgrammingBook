#include <iostream>

class Complex {

	private:
		int real;
		int imaginary;

	public:
		Complex(int r = 0, int i = 0) {
			real = r;
			imaginary = i;
		}

		Complex operator + (const Complex obj) {
			Complex res(obj.real + real, obj.imaginary + imaginary);
			return res;
		}

		Complex operator + (const int num) {
			Complex res(num + real, imaginary);
			return res;
		}

		Complex operator - (const Complex obj) {
			Complex res(obj.real - real, obj.imaginary - imaginary);
			return res;
		}

		Complex operator - (const int num) {
			Complex res(real - num, imaginary);
			return res;
		}

		Complex operator * (const int num) {
			Complex res(num * real, num * imaginary);
			return res;
		}

		std::string str() {
			return std::to_string(real) + " + " + std::to_string(imaginary) + "i";
		}

};

int main() {
	Complex c1(1, 3), c2(2, 6);
	Complex c3 = c1 + c2;
	std::cout << c3.str() << std::endl;
	return 0;
}
