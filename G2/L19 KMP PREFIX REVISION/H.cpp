#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	vector<int> z = z_function(s);
	for (auto i : z) cout << i << " ";
	cout << endl;
	int x = 1, n = 1;
	while (2 * x < s.size()) {
		cout << s.substr(0, x) << " " << s.substr(x, x) << " " << s.substr(2 * x, s.size() - 2 * x);
		if (s.substr(0, x) == s.substr(x, x)) cout << n++;
		cout << endl;
		x++;
	}
	for (int i = 1; i < z.size(); i++) {
		if (z[i] > i) cnt++;
	}
	cout << cnt;
	return 0;
}