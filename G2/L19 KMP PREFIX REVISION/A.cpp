#include <iostream>
#include <vector>
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

bool KMP(string txt, string pat) {
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			return true;
		}
	}
	return false;
}

int main() {
	string s, t;
	cin >> s >> t;
	string OG = s;
	int cnt = 1;
	while (s.size() < t.size()) {
		s += OG;
		cnt++;
	}
	if (KMP(s, t)) {
		cout << cnt;
		return 0;
	}
	if (KMP(s + OG, t)) {
		cout << ++cnt;
		return 0;
	}
	cout << -1;
	return 0;
}