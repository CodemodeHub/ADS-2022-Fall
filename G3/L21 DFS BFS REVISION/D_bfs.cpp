#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {

	cin >> a >> b;

	if (a > b) {
		cout << a - b << "\n";
		while (a != b) {
			cout << --a << " ";
		}
		return 0;
	}


	
	// vector<bool> v(10);
	map<int, bool> m;
	map<int, int> p;

	queue<pair<int, int> > q;
	// q.push({ a, 0 });
	q.push(make_pair(a, 0));
	m[a] = true;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int num = front.first;
		int step = front.second;
		if (num == b) {
			cout << step << "\n";
			vector<int> v;
			for (int i = b; i != a; i = p[i]) {
				// cout << i << " ";
				v.push_back(i);
			}
			for (int i = v.size() - 1; i >= 0; i--) {
				cout << v[i] << " ";
			}
			return 0;
		}

		if (num - 1 > 0 && !m[num - 1]) {
			q.push({ num - 1, step + 1 });
			m[num - 1] = true;
			p[num - 1] = num;
		}
		if (!m[num * 2]) {
			q.push({ num * 2, step + 1 });
			m[num * 2] = true;
			p[num * 2] = num;
		}
	}

	return 0;
}