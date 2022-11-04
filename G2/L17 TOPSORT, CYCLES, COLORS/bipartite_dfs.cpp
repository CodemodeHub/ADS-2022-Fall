#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > g;
vector<int> colors;

void dfs(int v) {
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 0) {
			colors[u] = 1 + colors[v] % 2;
			dfs(u);
		}
	}
}

bool dfs2(int v) {
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == colors[v]) {
			return false;
		} else {
			dfs2(u);
		}
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
	colors[0] = 1;
	dfs(0);
	for (int i = 0; i < m; i++) {
		cout << colors[i] << " ";
	}

	return 0;
}

// 0 - unvisited
// 1 - red
// 2 - blue