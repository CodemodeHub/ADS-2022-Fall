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
				visited[u] = true;
				d[u] = d[cur] + 1;
				q.push(u);
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
	d.resize(m);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(1);
	for (auto i : d) {
		cout << i << " ";
	}

	return 0;
}