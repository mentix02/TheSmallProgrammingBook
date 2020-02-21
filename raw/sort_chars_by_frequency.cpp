#include <queue>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> get_frequency(string s) {
    unordered_map<char, int> m;
    for (char c : s)
        m[c]++;
    return m;
}

priority_queue<pair<int, char>> make_q(unordered_map<char, int>& um) {
    priority_queue<pair<int, char>> q;
    for (auto p : um)
        q.push(make_pair(p.second, p.first));
    return q;
}

string frequencySort(string s) {
    string builder;
    auto um = get_frequency(s);
    auto q  = make_q(um);
    // empty queue
    while (!q.empty()) {
        auto item = q.top();
        q.pop();
        builder.append(item.first, item.second);
    }
    return builder;
}

int main() {
	string s = "Aaaabb";
	cout << frequencySort(s) << endl;
	return 0;
}
