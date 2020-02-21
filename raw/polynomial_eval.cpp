#include <vector>
#include <iostream>

int factorial(int n) {
	if (n < 2) {
		return 1;
	} else {
		int total = 1;
		for (int i = 2; i <= n; ++i) {
			total *= i;
		}
		return total;
	}
}

float nCr(int n, int r) {
	float res = factorial(n) / ((factorial(n-r) * factorial(r)));
	std::cout << res << std::endl;
	return res;
}

float value_at(std::vector<float> v, float n) {
	int ind = v.size();
	float total = 0;
	for (float num : v) {
		total += num * nCr(n, --ind);
	}
	return total;
}

int main() {
	float n = 0.6;
	std::vector<float> arr = {1, 2, 7, 0, 5};
	std::cout << value_at(arr, n) << std::endl;
	return 0;
}
