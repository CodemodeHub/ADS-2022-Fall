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
	string friendsCity, myCity;
	int n;
	cin >> friendsCity >> n;
	friendsCity[0] += 32;
	// 'A' -> 65
	// 'a' -> 97
	vector<string> myCities(n);
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		cin >> myCities[i];
		myCities[i][0] += 32;
	}
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		vector<int> pi = prefixFunction(myCities[i] + friendsCity);
		int prefSufSize = pi.back();
		if (maxi < prefSufSize) {
			maxi = prefSufSize;
			ans.clear();
			ans.push_back(myCities[i]);
		} else if (maxi == prefSufSize) {
			ans.push_back(myCities[i]);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		ans[i][0] -= 32;
		cout << ans[i] << "\n";
	}


	return 0;
}