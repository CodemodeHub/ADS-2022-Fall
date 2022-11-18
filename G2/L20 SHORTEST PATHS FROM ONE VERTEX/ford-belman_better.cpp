#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int from;
	int to;
	int cost;

	Edge() {}

	Edge(int from, int to, int cost) {
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
};

int main() {

	int m, n, s;
	cin >> m >> n;
	vector<Edge> edges(n);
	vector<int> d(m, 1e9);
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = Edge(u, v, w);
	}
	cin >> s;
	d[s] = 0;

	while (true) {
		bool hasChanged = false;
		for (int j = 0; j < n; j++) {
			if (d[edges[j].to] > d[edges[j].from] + edges[j].cost) {
				d[edges[j].to] = d[edges[j].from] + edges[j].cost;
				hasChanged = true;
			}
		}
		if (!hasChanged) break;
	}
	for (auto i : d) cout << i << ' ';


	return 0;
}
// O((|V| - 1)* |E| )
// 0 -> 1 = 50
// 0 -> 2 = 100
// 1 -> 2 = 30