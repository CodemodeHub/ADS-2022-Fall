#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int> > g;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < g[v].size(); i++) {
		if (!visited[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {

	cin >> m >> n;
	g.resize(m);
	visited.resize(m);

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}

	// dfs(0);

	stack<int> st;
	st.push(0);
	visited[0] = true;
	cout << 0 << " ";
	while (!st.empty()) {
		int top = st.top();
		st.pop();
		for (int i = 0; i < g[top].size(); i++) {
			if (!visited[g[top][i]]) {
				cout << g[top][i] << " ";
				visited[g[top][i]] = true;
				st.push(g[top][i]);
			}
		}
	}


	return 0;
}