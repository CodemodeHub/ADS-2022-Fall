#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int dsu_get(int v) {
	// return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
	if (v == p[v]) {
		return v;
	} else {
		return p[v] = dsu_get(p[v]);
	}
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	// if (rand() % 2)
	// 	swap(a, b);
	if (a != b)
		p[a] = b;
}

int main() {

	int m, n;
	cin >> m >> n;
	vector <pair<int, pair<int, int> > > g; // вес - вершина 1 - вершина 2

	int total_cost = 0;
	vector<pair<int, int> > res;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g.push_back({ w, {u, v} });
	}

	sort(g.begin(), g.end());
	p.resize(m);
	for (int i = 0; i < m; ++i)
		p[i] = i;
	for (int i = 0; i < n; ++i) {
		int u = g[i].second.first, v = g[i].second.second, cost = g[i].first;
		if (dsu_get(u) != dsu_get(v)) {
			total_cost += cost;
			res.push_back(g[i].second);
			dsu_unite(u, v);
		}
	}

	cout << total_cost << "\n";
	for (auto i : res) {
		printf("%d->%d\n", i.first + 1, i.second + 1);
	}

	return 0;
}