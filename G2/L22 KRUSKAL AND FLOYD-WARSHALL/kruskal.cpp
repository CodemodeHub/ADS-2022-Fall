#include <bits/stdc++.h>
using namespace std;

int main() {

	int m, n;
	cin >> m >> n;
	vector<pair<int, pair<int, int> > > g(n); // вес - вершина 1 - вершина 2
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[i] = { w, {u, v} };
	}
	int total_cost = 0;
	vector<pair<int, int> > res;
	sort(g.begin(), g.end()); // O(M LogN + N^2)
	vector<int> tree_id(m);

	for (int i = 0; i < m; ++i)
		tree_id[i] = i;

	for (int i = 0; i < n; ++i) {
		int u = g[i].second.first, v = g[i].second.second, cost = g[i].first;
		if (tree_id[u] != tree_id[v]) {
			total_cost += cost;
			res.push_back({ u, v });
			int old_id = tree_id[v], new_id = tree_id[u];
			for (int j = 0; j < m; ++j)
				if (tree_id[j] == old_id)
					tree_id[j] = new_id;
		}
	}
	cout << total_cost << "\n";
	for (auto i : res) {
		printf("%d->%d\n", i.first + 1, i.second + 1);
	}
	return 0;
}