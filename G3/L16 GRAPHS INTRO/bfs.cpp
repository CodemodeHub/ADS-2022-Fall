#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		cout << cur << " ";
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (!visited[u]) {
				q.push(u);
				visited[u] = true;
			}
		}
		q.pop();
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
	bfs(0);
	return 0;
}