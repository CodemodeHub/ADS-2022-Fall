#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int> > g;
vector<bool> visited;
vector<int> colors;

bool detectCycle(int v, pair<int, int> toIgnore) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (toIgnore.first == v && toIgnore.second == u) continue;
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (detectCycle(u, toIgnore)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

int main() {

	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	colors.resize(m);

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			pair<int, int> toIgnore = { i, g[i][j] };
			bool hasCycle = false;
			for (int k = 0; k < m; k++) {
				if (detectCycle(k, toIgnore)) {
					hasCycle = true;
					break;
				}
			}
			if (!hasCycle) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";


	return 0;
}