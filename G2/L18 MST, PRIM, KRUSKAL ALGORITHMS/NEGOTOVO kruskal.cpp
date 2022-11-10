#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > g;
vector<bool> visited;

int cost = 0;
vector<pair<int, int> > res;

int main() {

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}
	vector<int> tree_id(m);
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < m; i++) {
		tree_id[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		if (tree_id[a] != tree_id[b]) {
			cost += l;
			res.push_back(make_pair(a, b));
			int old_id = tree_id[b], new_id = tree_id[a];
			for (int j = 0; j < n; ++j)
				if (tree_id[j] == old_id)
					tree_id[j] = new_id;
		}
	}

	return 0;
}