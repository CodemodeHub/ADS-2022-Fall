#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int p = 1;
char decrypt(int n) {
	char ans = (n / p) + 97;
	p <<= 1;
	// p *= 2;
	return ans;
}

int main() {

	int n;
	cin >> n;
	vector<ull> v;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			cout << decrypt(v[i]);
			continue;
		}
		cout << decrypt(v[i] - v[i - 1]);
	}

	return 0;
}