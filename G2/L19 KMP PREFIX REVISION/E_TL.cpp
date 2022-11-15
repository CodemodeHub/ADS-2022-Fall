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
	int q, k;
	string s;
	cin >> q;
	while (q--) {
		cin >> s >> k;
		string original = s;
		vector<int> pi = prefixFunction(original);
		string toAdd = original.substr(pi.back(), original.size());
		while (KMP(s, original).size() < k) {
			s += toAdd;
		}
		cout << s.size() << "\n";
	}
	return 0;
}
// O(Q * (|S| + |OG|) * Log(K))