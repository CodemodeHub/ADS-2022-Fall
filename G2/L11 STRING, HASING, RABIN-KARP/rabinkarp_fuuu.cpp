#include <iostream>
using namespace std;

int main() {

	string s = "biba i boba addis abeba";
	string pattern = "ba";
	for (int i = 0; i < s.size() - pattern.size() + 1; i++) {
		if (s.substr(i, pattern.size()) == pattern) {
			cout << i << " ";
		}
	}

	return 0;
}