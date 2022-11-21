#include <bits/stdc++.h>
using namespace std;

int m, n, cnt;
vector<vector<int> > g;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!visited[to]) {
			if (g[to].size() > g[v].size()) cnt++;
			dfs(to);
		}
	}
}

int main() {

	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	cout << cnt;

	return 0;
}