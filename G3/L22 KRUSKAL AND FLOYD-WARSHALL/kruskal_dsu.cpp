#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int dsuGet(int v) {
	if (v == p[v]) return v;
	else return p[v] = dsuGet(p[v]);
}

void dsuUnite(int u, int v) {
	u = dsuGet(u);
	v = dsuGet(v);
	// if (rand() % 2 == 0) {
	// 	swap(a, b);
	// }
	if (u != v) {
		p[u] = v;
	}
}


int main() {

	vector<pair<int, pair<int, int> > > edges;
	int m, n;
	cin >> m >> n;
	p.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({ w, {u, v} });
		// edges.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(edges.begin(), edges.end()); // O(N LogM)

	for (int i = 0; i < m; i++) {
		p[i] = i;
	}

	int totalCost = 0;
	vector<pair<int, int> > res;


	for (int i = 0; i < n; i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int cost = edges[i].first;
		if (dsuGet(u) != dsuGet(v)) {
			totalCost += cost;
			res.push_back({ u + 1, v + 1 });
			dsuUnite(u, v);
		}
	}
	cout << totalCost << "\n";
	for (int i = 0; i < m - 1; i++) {
		printf("%d->%d\n", res[i].first, res[i].second);
	}

	return 0;
} // O(E LogV + E^2)