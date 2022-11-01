#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector <int> > g;
vector<bool> visited;
vector<int> components;

void dfs(int v, int x) {
	visited[v] = true;
	components[x]++;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u]) {
			components[x]++;
			dfs(u, x);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (!visited[u]) {
				visited[u] = true;
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
	components.resize(m);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int x = 0;
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			dfs(i, x);
			x++;
		}
	}
	for (auto i : components) {
		cout << i << " ";
	}


	return 0;
}