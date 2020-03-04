#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    bool valid(int row, int col, vector<int>& v) {
        for (int i = 0; i < row; i++) {
            if (v[i] == col) return false;
            if (v[i] - col == row - i) return false;
            if (v[i] - col == i - row) return false;
        }
        return true;
    }

    void solve(int row, vector<int>& b, vector<vector<string>>& res, int n) {
        if (row == n) {
            vector<string> temp(n, string(n, '.'));
            for (int i = 0; i < n; i++) temp[i][b[i]] = 'Q';
            res.push_back(temp);
        } else {
            for (int i = 0; i < n; i++) {
                if (valid(row, i, b)) {
                    b[row] = i;
                    solve(row+1, b, res, n);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> b(n, 0);
        solve(0, b, ret, n);
        return ret;
    }
};

void interactive() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	auto s = Solution().solveNQueens(n);
	for (auto v : s) {
		for (auto i : v) {
			for (auto c : i) {
				cout << c;
			}
			cout << endl;
		}
		for (int i = 0; i < n; ++i) cout << "=";
		cout << endl;
	}
	cout << "Found " << s.size() << " solutions." << endl;
}

void stats() {
	for (int i = 0; i < 20; ++i) {
		cout << "N : " << i << " | Solutions : " << Solution().solveNQueens(i).size() << endl;
	}
}

int main() {
	interactive();
	return 0;
}
