#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> p;
vector<int> colors; // 0 unvis, 1 red, 2 blue
int cycle_start, cycle_end;

bool dfs(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) {
			cycle_start = u;
			cycle_end = v;
			return true;
		}
		if (colors[u] == 0) {
			p[u] = v;
			if (dfs(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

int main() {
	int m, n;
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	p.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
	cycle_start = -1;
	for (int i = 0; i < m; i++) {
		if (dfs(i)) break;
	}
	if (cycle_start == -1) {
		cout << "NO CYCLES";
	} else {
		vector<int> cycle;
		for (int v = cycle_end; v != cycle_start; v = p[v]) {
			cycle.push_back(v);
		}
		cycle.push_back(cycle_start);
		reverse(cycle.begin(), cycle.end());
		for (auto i : cycle) {
			cout << i + 1 << " ";
		}
	}

	return 0;
}