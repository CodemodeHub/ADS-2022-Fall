#include <bits/stdc++.h>
using namespace std;

int search(string s, string pattern, int q = 1e9 + 7, int d = 31) {
	int p = 0, t = 0, h = 1, i, j;
	int cnt = 0;
	for (i = 0; i < pattern.size() - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < pattern.size(); i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + s[i]) % q;
	}

	for (i = 0; i <= s.size() - pattern.size(); i++) {
		if (p == t) {
			cnt++;
		}

		if (i < s.size() - pattern.size()) {
			t = (d * (t - s[i] * h) + s[i + pattern.size()]) % q;
			if (t < 0) t += q;
		}
	}
	return cnt;
}

int main() {

	string s;
	cin >> s;
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << search(s, s.substr(a, b - a + 1)) << "\n";
	}

	return 0;
}