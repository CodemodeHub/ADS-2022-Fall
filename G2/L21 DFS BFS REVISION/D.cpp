#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int a, b;
	cin >> a >> b;
	if (a > b) {
		cout << a - b << endl;
		while (a != b) {
			cout << --a << " ";
		}
		return 0;
	}
	queue<pair<int, int> > q;
	map<int, int> p;
	q.push({ a, 0 });
	set<int> s;
	while (!q.empty()) {
		auto front = q.front();
		int num = front.first;
		int step = front.second;

		if (s.find(num * 2) == s.end()) {
			s.insert(num * 2);
			q.push({ num * 2, step + 1 });
			p[num * 2] = num;
		}
		if (num - 1 > 0 && s.find(num - 1) == s.end()) {
			s.insert(num - 1);
			q.push({ num - 1, step + 1 });
			p[num - 1] = num;
		}

		if (num == b) {
			cout << step << "\n";
			vector<int> v;
			for (int i = b; i != a; i = p[i]) {
				v.push_back(p[i]);
			}
			for (int i = v.size() - 1; i >= 0; i--) {
				cout << v[i] << " ";
			}
			return 0;
		}

		q.pop();
	}


	return 0;
}