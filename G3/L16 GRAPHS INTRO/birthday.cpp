#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > g;
vector<int> components;
vector<bool> visited;
int x;

void dfs(int v) {
	visited[v] = true;
	components[x]++;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u]) {
			visited[u] = true;
			dfs(u);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	components[x]++;
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
				components[x]++;
			}
		}
		q.pop();
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	components.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			bfs(i);
			x++;
		}
	}
	for (auto i : components) cout << i << " ";
	// int ans = 1e9;
	// for (int i = 0; i < components.size(); i++) {
	// 	if (components[i] > 0 && components[i] < ans) {
	// 		ans = components[i];
	// 	}
	// }
	// cout << ans;

	return 0;
}