#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s) { // O(N)
	vector<int> pi(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> KMP(string txt, string pat) { // O(N)
	vector<int> ans;
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			ans.push_back(i - 2 * pat.size());
		}
	}
	return ans;
}

int main() {

	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 1; i < s.size(); i++) {
		for (int j = i + 1; j < s.size(); j++) {
			string a, b, c;
			a = s.substr(0, i);
			b = s.substr(i, j - i);
			c = s.substr(j, s.size() - j + 1);
			printf("%s %s %s", a.c_str(), b.c_str(), c.c_str());
			if (a == b) {
				cnt++;
				cout << " +";
			}
			cout << "\n";
		}
	}
	cout << cnt;

	return 0;
}