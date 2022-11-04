#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > g;
vector<bool> visited;
vector<int> p;

void dfs(int v) {
	visited[v] = true;
	p.push_back(v);
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u]) {
			dfs(u);
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	// reverse(p.begin(), p.end());
	for (auto i : p) {
		cout << i << " ";
	}

	return 0;
}