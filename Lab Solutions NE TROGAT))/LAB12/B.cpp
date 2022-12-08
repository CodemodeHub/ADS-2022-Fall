#include <bits/stdc++.h>
using namespace std;

int m, n, s, a, b, f;


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

vector<Edge> edges;

int fordBellman(int s, int f) {
	vector<int> d(m + 1, 1e9);
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
	return d[f];
}

int main() {


	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
	}
	cin >> s >> a >> b >> f;
	int sa = fordBellman(s, a);
	int sb = fordBellman(s, b);
	int ab = fordBellman(a, b);
	int ba = fordBellman(b, a);
	int af = fordBellman(a, f);
	int bf = fordBellman(b, f);

	if (sa + ab + bf >= 1e9 && sb + ba + af >= 1e9) {
		cout << -1;
	} else {
		cout << min(sa + ab + bf, sb + ba + af);
	}




	return 0;
}