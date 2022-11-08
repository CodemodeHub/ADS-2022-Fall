#include <bits/stdc++.h>
using namespace std;

string LCS(vector<string>& v) {
	
}

int main() {

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	cout << LCS(v);

	return 0;
}