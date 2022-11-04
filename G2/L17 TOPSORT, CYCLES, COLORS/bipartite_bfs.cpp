#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int> > g;
vector<int> colors;

bool isBipartite(int v) {
	queue<pair<int, int> > q;
	q.push({ v, 1 });
	colors[v] = 1;
	while (!q.empty()) {
		pair<int, int> u = q.front();
		int val = u.first;
		int col = u.second;
		for (int i = 0; i < g[val].size(); i++) {
			if (colors[g[val][i]] == col) {
				return false;
			}
			if (colors[g[val][i]] == 0) {
				if (col == 1) {
					colors[g[val][i]] = 2;
				} else {
					colors[g[val][i]] = 1;
				}
				q.push({g[val][i] , colors[g[val][i]] });
			}
		}
		q.pop();
	}
	return true;
}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	colors.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}

	for (int i = 0; i < m; i++) {
		cout << colors[i] << " ";
	}

	return 0;
}

// 0 - unvisited
// 1 - red
// 2 - blue