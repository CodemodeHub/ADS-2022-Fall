#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;
vector<int> d;

void bfs(int v) {
	queue<int> q;
	q.push(v);
	d[v] = 0;
	visited[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (!visited[u]) {
				q.push(u);
				d[u] = d[cur] + 1;
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
	d.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(2);
	for (auto i : d) {
		cout << i << " ";
	}
	return 0;
}