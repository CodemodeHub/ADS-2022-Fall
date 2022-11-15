#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	int x = 1;
	while (2 * x < s.size()) {
		string a, b, c;
		a = s.substr(0, x);
		b = s.substr(x, x);
		c = s.substr(2 * x, s.size() - 2 * x);
		cout << a << " " << b << " " << c << endl;
		if (a == b) cnt++;
		x++;
	}
	cout << cnt;

	return 0;
}