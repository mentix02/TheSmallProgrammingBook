#include <vector>
#include <iostream>

int len(int n) {
	int len = 0;
	do {
		len++;
		n /= 10;
	} while (n > 0);
	return len;
}

int findNums(std::vector<int>& nums) {
	int total = 0;
	for (int num : nums) {
		if (len(num) % 2 == 0) total++;
	}
	return total;
}

int main() {
	std::vector<int> nums = {555,901,482,1771};
	std::cout << findNums(nums) << std::endl;
	return 0;
}
