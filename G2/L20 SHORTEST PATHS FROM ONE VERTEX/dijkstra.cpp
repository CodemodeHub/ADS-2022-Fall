#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	int m, n, start, end;
	cin >> m >> n;
	vector<vector<pair<int, int> > > g(m);
	vector<bool> visited(m);
	vector<int> d(m, INF);
	vector<int> p(m, -1);
	for (int i = 0; i < n; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		g[from].push_back({ to, cost });
	}
	cin >> start >> end;
	d[start] = 0;
	for (int i = 0; i < m; i++) {
		int v = -1;
		for (int j = 0; j < m; j++) {
			if (!visited[j] && (v == -1 || d[j] < d[v])) {
				v = j;
			}
		}
		visited[v] = true;
		for (int j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first;
			int cost = g[v][j].second;
			if (d[to] > d[v] + cost) {
				d[to] = d[v] + cost;
				p[to] = v;
			}
		}
	}
	vector<int> path;
	path.push_back(end);
	for (int i = p[end]; i != start; i = p[i]) {
		path.push_back(i);
	}
	path.push_back(start);
	reverse(path.begin(), path.end());
	for (auto i : path) cout << i << " ";
	cout << "\n";

	for (auto i : d) cout << i << " ";
	// for (auto i : p) cout << i << " ";
	return 0;
} // O(M^2 * N)

// 1. number of vertices
// 2. number of edges
// 3. input relations