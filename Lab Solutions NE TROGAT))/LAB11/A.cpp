#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > g;
vector<int> p;

int dsu_get(int v) {
	if (v == p[v]) {
		return v;
	} else {
		return p[v] = dsu_get(p[v]);
	}
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (a != b)
		p[a] = b;
}

int main() {

	int n, q, totalCost = 0;
	cin >> n >> q;
	p.resize(n);
	while (q--) {
		int l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		for (int i = l; i < r; i++) {
			for (int j = i + 1; j <= r; j++) {
				if (i != j) {
					g.push_back({ c, {i, j} });
				}
			}
		}
	}
	
	sort(g.begin(), g.end());

	for (int i = 0; i < n; ++i)
		p[i] = i;
	
	for (int i = 0; i < g.size(); ++i) {
		int u = g[i].second.first;
		int v = g[i].second.second;
		int cost = g[i].first;
		if (dsu_get(u) != dsu_get(v)) {
			totalCost += cost;
			dsu_unite(u, v);
		}
	}

	cout << totalCost;


	return 0;
}