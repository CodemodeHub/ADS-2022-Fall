#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> visited;
vector<int> p, min_e;
int ans = 0;
const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		g[i].resize(n);
	}
	visited.resize(n);
	p.assign(n, -1);
	min_e.assign(n, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			if (g[i][j] == 0) g[i][j] = INF;
		}
	}
	min_e[0] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && (v == -1 || min_e[j] < min_e[v])) {
				v = j;
			}
		}
		if (min_e[v] == INF) {
			cout << "NO MST!";
			return 0;
		}
		visited[v] = true;
		if (p[v] != -1) {
			cout << v << " " << p[v] << "\n";
			ans += g[v][p[v]];
		}
		for (int j = 0; j < n; j++) {
			if (g[v][j] < min_e[j]) {
				min_e[j] = g[v][j];
				p[j] = v;
			}
		}
	}
	cout << ans;
	return 0;
}