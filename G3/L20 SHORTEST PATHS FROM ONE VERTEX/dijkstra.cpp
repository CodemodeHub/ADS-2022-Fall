#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	int m, n, s, e;
	cin >> m >> n;
	vector<vector<pair<int, int> > > g(m);
	vector<bool> used(m);
	vector<int> d(m, INF);
	vector<int> p(m, -1), path;
	// for (auto i : d) cout << i << " ";

	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
	}
	cin >> s >> e;
	d[s] = 0;

	for (int i = 0; i < m; i++) {
		int v = -1;
		for (int j = 0; j < m; j++) {
			if (!used[j] && (v == -1 || d[j] < d[v])) {
				v = j;
			}
		}
		used[v] = true;
		for (int j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first;
			int weight = g[v][j].second;
			if (d[to] > d[v] + weight) {
				d[to] = d[v] + weight;
				p[to] = v;
			}
		}
	}
	// for (int i : d) cout << i << " ";
	for (int i : p) cout << i << " ";
	path.push_back(e);
	for (int i = e; i != s; i = p[i]) {
		path.push_back(p[i]);
	}
	// path.push_back(s);
	reverse(path.begin(), path.end());
	for (auto i : path) cout << i << " ";

} // O(|V|^2 * |E|)