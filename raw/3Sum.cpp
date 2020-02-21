#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() == 0) {
    	vector<vector<int>> v;
    	return v;
    }
    set<vector<int>> r;
    sort(nums.begin(), nums.end());
    for (unsigned i = 0; i < nums.size() - 1; i++) {
        int left = i + 1;
        int right = nums.size() - 1;
        int element = nums[i];
        while (left < right) {
            int sum = element + nums[left] + nums[right];
            if (sum == 0) {
                r.insert({element, nums[left], nums[right]});
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    vector<vector<int>> v(r.size());
    copy(r.begin(), r.end(), v.begin());
    return v;
}

int main() {
	vector<int> i = {};
	auto r = threeSum(i);
	for (auto v : r) {
		cout << "( ";
		for (auto num : v)
			cout << num << ", ";
		cout << ")" << " = 0" << endl;
	}
	return 0;
}
