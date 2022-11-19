#include <bits/stdc++.h>

using namespace std;

vector<int> prefix(string s) {
	vector <int> pi(s.size());

	int i = 1, j = pi[i - 1];

	while (i != s.size()) {
		j = pi[i - 1];

		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}

		if (s[i] == s[j]) {
			j++;
		}

		pi[i] = j;
		i++;
	}

	return pi;
}

int main() {
	string s;
	cin >> s;

	s[0] += 32;

	int n;
	cin >> n;

	vector <string> store(n);
	vector <string> ans;

	for (int i = 0; i < n; i++) {
		cin >> store[i];
		store[i][0] += 32;
	}

	int maxi = -1;

	for (int i = 0; i < n; i++) {
		string temp = store[i] + s;

		vector <int> v = prefix(temp);

		// for (int i = 0; i < v.size(); i++) {
		//   cout << v[i] << " ";
		// }

		// cout << endl;

		int occurence = v.back();
		if (occurence == 0) continue;
		if (maxi < occurence) {
			if (occurence >= s.size()) {
				ans.push_back(store[i]);
			}
			else {
				maxi = occurence;
				ans.clear();
				ans.push_back(store[i]);
			}
		}
		else if (maxi == occurence) {
			ans.push_back(store[i]);
		}
	}
	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		ans[i][0] -= 32;
		cout << ans[i] << endl;
	}
	return 0;
}