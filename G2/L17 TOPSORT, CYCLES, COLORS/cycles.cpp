#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > g;
vector<int> colors;
vector<int> p;
int cycle_start, cycle_end;


bool dfs(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 0) {
			p[u] = v;
			if (dfs(u)) return true;
		} else if (colors[u] == 1) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	colors[v] = 2;
	return false;
}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	colors.resize(m);
	p.assign(m, -1);
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
		cout << "NO CYCLE";
	} else {
		cout << "CYCLE:\n";
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for (int v = cycle_end; v != cycle_start; v = p[v]) {
			cycle.push_back(v);
		}
		reverse(cycle.begin(), cycle.end());
		for (auto i : cycle) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}