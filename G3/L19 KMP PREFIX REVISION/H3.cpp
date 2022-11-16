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
	vector<int> pi = prefixFunction(s);
	int k = s.size() - pi.back();
	for (int i = 0; i < pi.size(); i++) {
		int n = i;
		if (n % k == 0) {
			if ((n / k) % 2 == 0) cnt++;
		}
	}
	cout << cnt;

	return 0;
}