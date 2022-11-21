#include <bits/stdc++.h>
using namespace std;

int m, n, q;
vector<vector<int> > g;
vector<bool> colors, visited;

int bfs(int v) {
	if (colors[v]) return 0;
	int cnt = 0;
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		cnt++;
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int to = g[u][i];
			if (!visited[to]) {
				visited[to] = true;
				if (colors[to]) {
					visited.assign(m, false);
					return cnt;
				} else {
					q.push(to);
				}
			}
		}
	}
	visited.assign(m, false);
	return -1;
}

int main() {
	
	cin >> m >> n >> q;
	g.resize(m);
	visited.resize(m);
	colors.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while (q--) {
		int command, vertex;
		cin >> command >> vertex;
		vertex--;
		if (command == 1) {
			colors[vertex] = true;
		} else {
			cout << bfs(vertex) << "\n";
		}
	}

	return 0;
}