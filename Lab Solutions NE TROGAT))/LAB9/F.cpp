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

vector<int> KMP(string txt, string pat) {
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
	string s, t;
	cin >> s >> t;
	vector<int> indices = KMP(s, t);
	cout << indices.size() << "\n";
	for (auto i : indices) {
		cout << i + 1 << " ";
	}
	
	return 0;
}