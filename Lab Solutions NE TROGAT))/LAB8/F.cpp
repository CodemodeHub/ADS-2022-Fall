#include <bits/stdc++.h>
using namespace std;

int distinctSubsts(string s) {
	unordered_set<string> us;
	for (int i = 0; i < s.size(); i++) {
		string ss = "";
		for (int j = i; j < s.size(); j++) {
			ss += s[j];
			us.insert(ss);
		}
	}
	return us.size();
}

int main() {

	string s;
	cin >> s;
	cout << distinctSubsts(s);

	return 0;
}