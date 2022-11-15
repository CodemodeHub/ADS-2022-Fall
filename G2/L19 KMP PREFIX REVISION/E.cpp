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

int main() {
	int q, k;
	string s;
	cin >> q;
	while (q--) {
		cin >> s >> k;
		vector<int> pi = prefixFunction(s);
		cout << s.size() + (k - 1) * (s.size() - pi.back()) << "\n";
	}
	return 0;
}
// O(Q * S.size);