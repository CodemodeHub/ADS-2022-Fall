#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> vis;
set<int> deleted_nodes;

void dfs(int v) {
	vis[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!vis[u] && deleted_nodes.find(u) == deleted_nodes.end()) {
			dfs(u);
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	vis.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < m; i++) {
		deleted_nodes.insert(i);
		int comp = 0;
		for (int j = i + 1; j < m; j++) {
			if (!vis[j]) {
				dfs(j);
				comp++;
			}
		}
		vis.clear();
		vis.resize(m);
		cout << comp << "\n";
	}

	return 0;
}