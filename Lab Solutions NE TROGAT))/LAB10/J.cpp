#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int> > g;
vector<bool> visited;
vector<int> topsortVector, colors;

bool detectCycle(int v, pair<int, int> edge) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (v == edge.first && u == edge.second) continue;
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (detectCycle(u, edge)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

int main() {
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			bool hasCycle = false;
			for (int k = 0; k < m; k++) {
				if (detectCycle(k, { i, g[i][j] })) {
					hasCycle = true;
					break;
				}
			}
			if (!hasCycle) {
				cout << "YES";
				return 0;
			}
			colors.assign(m, 0);
		}
	}

	cout << "NO";
	return 0;
}