#include <bits/stdc++.h>
using namespace std;

int m, n, x, y;

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
	vector<int> d(m, 1e9);
	int age = 0;
	d[s] = age;
	while (true) {
		bool hasChanged = false;
		for (int j = 0; j < n; j++) {
			if (d[edges[j].to] > d[edges[j].from] + edges[j].cost) {
				d[edges[j].to] = d[edges[j].from] + edges[j].cost;
				hasChanged = true; // догадайтесь как найти минимальный возраст чтобы добраться из первой вершины в последнюю
			}
		}
		if (!hasChanged) break;
	}
	return d[f];
}

int main() {

	cin >> m;
	vector<pair<int, int> > cities(m);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cities[i] = { x,  y };
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) continue;
			int w = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
			edges.push_back(Edge(i, j, w));
		}
	}
	cout << fordBellman(0, m - 1);
	return 0;
}