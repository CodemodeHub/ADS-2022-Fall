#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s) {
	vector<int> pi(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

bool findSubstrings(string txt, string pat, int k) {
	int cnt = 0;
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			if (++cnt == k) return true;
		}
	}
	return false;
}

int main() {

	string s, t;
	int k;
	cin >> s >> k >> t;
	if (findSubstrings(t, s, k)) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}