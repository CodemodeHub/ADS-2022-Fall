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
	
	int n, k;
	cin >> n;
	string s;
	while (n--) {
		cin >> s >> k;
		int x = prefixFunction(s).back();
		// s = s.substr(x, s.size() - x);
		// while (KMP(ans, original).size() < k) {
		// 	ans += s;
		// } // O(n + (n * k))
		cout << s.size() + (k - 1) * (s.size() - x) << "\n";
		// O(n)
	}

	return 0;
}