#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

string hash_f(string s, int q = 1e9 + 7, int mul = 11) {
	ull p = 1;
	ull ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = (ans + ((s[i] - 47) * p) % q) % q;
		p = (p * mul) % q;
	}
	return to_string(ans);
}

int main() {

	int n;
	cin >> n;
	vector<string> v;
	
	for (int i = 0; i < n * 2; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	for (auto i : v) {
		string hash = hash_f(i);
		if (find(v.begin(), v.end(), hash) != v.end()) {
			printf("Hash string of \"%s\" is %s\n", i.c_str(), hash.c_str());
		}
	}
	return 0;
}