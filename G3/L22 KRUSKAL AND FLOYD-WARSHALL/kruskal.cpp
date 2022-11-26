#include <bits/stdc++.h>
using namespace std;


int main() {

	vector<pair<int, pair<int, int> > > edges;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({ w, {u, v} });
		// edges.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(edges.begin(), edges.end()); // O(N LogM)

	vector<int> c(m);
	for (int i = 0; i < m; i++) {
		c[i] = i;
	}

	int totalCost = 0;
	vector<pair<int, int> > res;


	for (int i = 0; i < n; i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int cost = edges[i].first;
		if (c[u] != c[v]) {
			totalCost += cost;
			res.push_back({ u + 1, v + 1 });
			int firstComponent = c[u];
			int secondComponent = c[v];
			for (int j = 0; j < n; j++) {
				if (c[j] == secondComponent) {
					c[j] = firstComponent;
				}
			}
		}
	}
	cout << totalCost << "\n";
	for (int i = 0; i < m - 1; i++) {
		printf("%d->%d\n", res[i].first, res[i].second);
	}

	return 0;
} // O(E LogV + E^2)