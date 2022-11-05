#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> vis;
vector<int> topsort_v, colors; // 0 unvis, 1 red, 2 blue

bool detectCycle(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (detectCycle(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

void topsort(int v) {
	vis[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!vis[u]) {
			topsort(u);
		}
	}
	topsort_v.push_back(v);
}

int main() {
	int m, n;
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	vis.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
	bool hasCycle = false;
	for (int i = 0; i < m; i++) {
		if (detectCycle(i)) {
			hasCycle = true;
			break;
		}
	}
	if (!hasCycle) {
		cout << "Possible\n";
		for (int i = 0; i < m; i++) {
			if (!vis[i]) {
				topsort(i);
			}
		}
		reverse(topsort_v.begin(), topsort_v.end());
		for (auto i : topsort_v) {
			cout << i + 1 << " ";
		}
	} else {
		cout << "Impossible";
	}

	return 0;
}