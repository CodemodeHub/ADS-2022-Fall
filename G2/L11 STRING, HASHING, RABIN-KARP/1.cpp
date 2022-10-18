#include <iostream>
using namespace std;

int hash_f(string s) {
	int p = 1;
	int q = 1e9 + 7;
	int hashed_s = 0;
	for (int i = 0; i < s.size(); i++) {
		hashed_s = (hashed_s + (s[i] - 'a' + 1) * p) % q;
		p = (p * 31) % q;
	}
	return hashed_s;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << hash_f(s1) << endl << hash_f(s2);
}

