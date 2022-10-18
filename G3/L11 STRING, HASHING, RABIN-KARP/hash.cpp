#include <iostream>
using namespace std;

int hashed_s(string s, int q = 1e9 + 7) {
	int p = 1;
	int hashed = 0;
	for (int i = 0; i < s.length(); i++) {
		hashed = (hashed + (s[i] - 'a' + 1) * p) % q;
		p = (p * 31) % q;
	}
	return hashed;
}

int main() {

	string s1, s2;
	cin >> s1;
	cin >> s2;
	cout << hashed_s(s1) << endl;
	cout << hashed_s(s2);
	return 0;
}