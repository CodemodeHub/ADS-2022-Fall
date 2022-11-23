#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {

	cin >> a >> b;
	// vector<bool> v(10);
	map<int, bool> m;

	queue<pair<int, int> > q;
	q.push({ a, 0 });
	m[a] = true;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int num = front.first;
		int step = front.second;

		if (num == b) {
			cout << step << "\n";
			return 0;
		}

		if (!m[num * 2]) {
			q.push({ num * 2, step + 1 });
			m[num * 2] = true;
		}
		if (num - 1 > 0 && !m[num - 1]) {
			q.push({ num - 1, step + 1 });
			m[num - 1] = true;
		}
	}

	return 0;
}