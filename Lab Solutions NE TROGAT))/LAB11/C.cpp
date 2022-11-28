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

	int v, e, x, y, totalCost = 0;
	cin >> v >> e >> x >> y;
	p.resize(v);
	int forBoth = min(x, y);
	for (int i = 0; i < e; i++) {
		string type;
		int u, v, c;
		cin >> type >> u >> v >> c;
		u--; v--;
		if (type == "big") {
			c *= x;
		} else if (type == "small") {
			c *= y;
		} else {
			c *= forBoth;
		}
		g.push_back({ c, {u, v} });
	}

	sort(g.begin(), g.end());

	for (int i = 0; i < v; ++i)
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