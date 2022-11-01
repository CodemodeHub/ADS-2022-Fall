#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	map<string, string> m;
	cin >> n;
	while (n--) {
		string oldname, newname;
		bool flag = false;
		cin >> oldname >> newname;
		for (auto i : m) {
			if (oldname == i.second) {
				m[i.first] = newname;
				flag = true;
				break;
			}
		}
		if (!flag) {
			m[oldname] = newname;
		}
	}
		cout << "CHECK\n";
		for (auto i : m) {
			cout << i.first << " " << i.second << endl;
		}
	}