#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;
	vector<int> v;
	while (a != b) {
		if (a < b) a *= 2;
		else {
			a--;
		}
		v.push_back(a);
	}
	cout << v.size() << "\n";
	for (int i : v) cout << i << " ";

	return 0;
}