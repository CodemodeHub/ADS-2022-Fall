#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int> > g;
vector<int> colors;

bool isBipartite(int v) {
	queue<int> q;
	colors[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (colors[u] == colors[cur]) {
				return false;
			}
			if (colors[u] == 0) {
				if (colors[cur] == 1) {
					colors[u] = 2;
				} else {
					colors[u] = 1;
				}
				q.push(u);
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
	cout << (isBipartite(0) ? "YES\n" : "NO\n");


	for (int i = 0; i < m; i++) {
		cout << colors[i] << " ";
	}

	return 0;
}

// 0 - unvisited
// 1 - red
// 2 - blue