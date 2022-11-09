#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int search(string s1, string s2, string pattern, int q = 1e9 + 7, int d = 31) {
	int p = 0, t = 0, tt = 0, h = 1, i, j;
	int cnt = 0;
	for (i = 0; i < pattern.size() - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < pattern.size(); i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + s1[i]) % q;
		tt = (d * tt + s2[i]) % q;
	}

	int sz = min(s1.size(), s2.size());
	for (i = 0; i <= sz - pattern.size(); i++) {
		if (p == t && p == tt)
			cnt++;

		if (i < sz - pattern.size()) {
			t = (d * (t - s1[i] * h) + s1[i + pattern.size()]) % q;
			tt = (d * (tt - s2[i] * h) + s2[i + pattern.size()]) % q;
			// if (t < 0) t += q;
			// if (tt < 0) tt += q;
		}
	}
	return cnt;
}

int main() {

	string s, t, parasite;
	cin >> s >> t >> parasite;
	cout << search(s, t, parasite);

	return 0;
}