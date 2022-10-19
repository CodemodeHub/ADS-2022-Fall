#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> prefixFunction(string s) {
	vector<int> pi(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> findSubstrings(string txt, string pat) {
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
map<string, bool> m;

bool isUnique(string s) {
	return !m[s];
}

int main() {
	string s;
	int k, cnt = 0;
	cin >> s >> k;
	// vector<int> pi = prefixFunction(s);
	for (int i = 0; i < s.size() - k; i++) {
		if (isUnique(s.substr(i, k))) {
			cnt++;
			m[s.substr(i, k)] = true;
		}
	}
	cout << cnt;
	return 0;
}