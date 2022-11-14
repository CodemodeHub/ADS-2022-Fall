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

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		int m;
		cin >> s >> m;
		vector<int> pi = prefixFunction(s);
		int k = s.size() - pi.back();
		cout << k * (m - 1) + s.size() << endl;
	}
	return 0;
}