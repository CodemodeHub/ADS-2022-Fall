#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
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
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	return 0;
}