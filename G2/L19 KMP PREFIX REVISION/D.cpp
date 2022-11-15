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
	string cityKenta;
	int n;
	cin >> cityKenta >> n;
	cityKenta[0] += 32;
	vector<string> myCities(n);
	for (int i = 0; i < n; i++) {
		cin >> myCities[i];
		myCities[i][0] += 32;
	}
	int maxi = -1;
	vector<string> ans;
	for (int i = 0; i < myCities.size(); i++) {
		string concat = myCities[i] + cityKenta;
		vector<int> pi = prefixFunction(concat);
		int longest = pi.back();
		if (maxi < longest) {
			maxi = longest;
			ans.clear();
			ans.push_back(myCities[i]);
		} else if (maxi == longest) {
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