#include <math.h>
#include <vector>
#include <string>
#include <iostream>

int minimum(int arr[], unsigned int size) {
	if (size == 0) {
		return -1;
	}
	int minimum = arr[0];
	for (unsigned int i = 0; i < size; ++i) {
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}
	return minimum;
}

template <typename T>
std::vector<T> add(std::vector<T> v1, std::vector<T> v2) {

	std::vector<T> r;

	int arr[] = {(int) v1.size(), (int) v2.size()};
	auto min = minimum(arr, 2);

	for (int i = 0; i < min; ++i) {
		r.push_back(v1[i] + v2[i]);
	}
	return r;
}

std::string repr(std::vector<std::string> v) {
	std::string builder = "[";
	for (auto item : v) {
		builder += " " + item;
	}
	return builder + " ]";
}

std::string repr(std::vector<int> v) {
	std::string builder = "[";
	for (auto item : v) {
		builder += " " + std::to_string(item);
	}
	return builder + " ]";
}

std::string repr(std::vector<float> v) {
	std::string builder = "[";
	for (auto item : v) {
		builder += " " + std::to_string((int) item);
	}
	return builder + " ]";
}

std::vector<float> map(float (*f)(int), std::vector<int> v) {
	std::vector<float> r;
	for (auto item : v) {
		r.push_back(f(item));
	}
	return r;
}

std::vector<int> map(int (*f)(int), std::vector<int> v) {
	std::vector<int> r;
	for (auto item : v) {
		r.push_back(f(item));
	}
	return r;
}

std::vector<int> mul(std::vector<int> v, int n) {
	std::vector<int> r;
	for (auto item : v) {
		r.push_back(n * item);
	}
	return r;
}

std::vector<std::string> map(std::string (*f)(int), std::vector<int> v) {
	std::vector<std::string> r;
	for (auto item : v) {
		r.push_back(f(item));
	}
	return r;
}

int square(int n) {
	return n * n;
}

std::string to_str(int n) {
	return std::to_string(n);
}

float root(int n) {
	return (float) sqrt(n);
}

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	auto squares = map(square, v);
	std::cout << "   " << repr(v) << std::endl;
	std::cout << " + " << repr(squares) << std::endl;
	std::cout << " = " << repr(add(v, squares)) << std::endl;
	return 0;
}
