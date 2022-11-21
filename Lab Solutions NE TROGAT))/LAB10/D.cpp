#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	set<int> visited;
	map<int, int> p;
	queue<pair<int, int> > q;
	q.push({ a, 0 });
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();
		int num = front.first;
		int step = front.second;
		if (num == b) {
			cout << step << "\n";
			vector<int> ans;
			ans.push_back(num);
			for (int i = p[num]; p.find(i) != p.end(); i = p[i]) {
				ans.push_back(i);
			}
			for (int i = ans.size() - 1; i >= 0; i--) {
				cout << ans[i] << " ";
			}
			return 0;
		}
		visited.insert(num);
		if (visited.find(num << 1) == visited.end()) {
			q.push({ num << 1, step + 1 });
			p[num << 1] = num;
		}
		if (num - 1 >= 0 && visited.find(num - 1) == visited.end()) {
			q.push({ num - 1, step + 1 });
			p[num - 1] = num;
		}
	}

	return 0;
}