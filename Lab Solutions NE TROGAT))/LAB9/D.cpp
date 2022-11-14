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

	string s, t;
	int n;
	cin >> s >> n;
	s[0] = tolower(s[0]);
	vector<pair<string, int> > v;
	vector<string> ans;
	int maxi = -1;
	while (n--) {
		cin >> t;
		t[0] = tolower(t[0]);
		vector<int> pi = prefixFunction(t + s);
		maxi = max(maxi, pi.back());
		v.push_back({ t, pi.back() });
	}
	for (auto i : v) {
		if (i.second == maxi) {
			ans.push_back(i.first);
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans) {
		i[0] = toupper(i[0]);
		cout << i << "\n";
	}

	return 0;
}