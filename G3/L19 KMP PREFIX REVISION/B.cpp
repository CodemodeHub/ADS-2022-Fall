#include <iostream>
#include <vector>
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

bool KMP(string txt, string pat, int k) { // O(N)
	int cnt = 0;
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			// cnt++;
			if (++cnt == k) return true;
		}
	}
	return false;
}

int main() {
	string s, t;
	int k;
	cin >> t >> k >> s;
	cout << (KMP(s, t, k) ? "YES" : "NO");
	return 0;
}