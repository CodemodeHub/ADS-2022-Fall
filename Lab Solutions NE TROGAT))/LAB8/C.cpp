#include <bits/stdc++.h>
using namespace std;

string hash_f(string s) {
	int p = 1;
	int q = 1e9 + 7;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		ans = (ans + ((s[i] - 47) * p) % q) % q;
		p = (p * 31) % q;
	}
	return to_string(ans);
}

vector<int> search(string s, string pattern, int q = 1e9 + 7, int d = 31) {
	int p = 0, t = 0, h = 1, i, j;
	vector<int> ans;
	for (i = 0; i < pattern.size() - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < pattern.size(); i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + s[i]) % q;
	}

	for (i = 0; i <= s.size() - pattern.size(); i++) {
		if (p == t) {
			for (j = 0; j < pattern.size(); j++) {
				if (s[i + j] != pattern[j]) break;
			}
			if (j == pattern.size()) {
				ans.push_back(i);
			}
		}

		if (i < s.size() - pattern.size()) {
			t = (d * (t - s[i] * h) + s[i + pattern.size()]) % q;
			if (t < 0) t += q;
		}
	}
	return ans;
}

int main() {

	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	// string hashed_s = hash_f(s);
	vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		auto occurences = search(s, v[i]);
		for (auto j : occurences) {
			for (int pos = j; pos < v[i].size() + j; pos++) {
				visited[pos] = true;
			}
		}
	}
	for (auto i : visited) {
		if (i == false) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";


	return 0;
}

// OPTIMIZATIONS:
// 1. Hash S only once.