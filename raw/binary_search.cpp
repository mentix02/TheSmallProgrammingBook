#include <vector>
#include <iostream>

template <typename T>
int search(const std::vector<T>& data, T target, int low, int high) {
	if (high >= low) {
		int mid = low + (high - low) / 2;
		if (data[mid] == target)
			return mid;
		else if (data[mid] > target)
			return search(data, target, low, mid - 1);
		else
			return search(data, target, mid + 1, high);
	}
	return -1;
}

int main() {
	int n, target;
	std::cout << "Enter the amount of numbers you want to enter : ";
	std::cin >> n;
	std::vector<int> v(n);
	for (int index = 0; index < n; ++index) {
		std::cout << "Enter number " << index + 1 << " : ";
		std::cin >> v[index];
	}
	std::cout << "Enter the number to look for : ";
	std::cin >> target;
	int index = search(v, target, 0, v.size() - 1);
	if (index != -1)
		std::cout << "Number found at " << index + 1 << "." << std::endl;
	else
		std::cout << "Number not found." << std::endl;
	return 0;
}
