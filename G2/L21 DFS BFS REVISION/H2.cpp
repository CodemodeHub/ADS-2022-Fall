#include <bits/stdc++.h>
using namespace std;

int m, n, a, b;
vector<vector<int> > g;
vector<bool> vis;

int main() {

	cin >> m >> n;
	g.resize(m);
	vis.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> a >> b;
	a--; b--;
	
	stack<int> st; // DFS ITERATIVE
	st.push(a);
	vis[a] = true;
	while (!st.empty()) {
		int top = st.top();
		for (int i = 0; i < g[top].size(); i++) {
			int to = g[top][i];
			if (!vis[to]) {
				if (to == b) {
					cout << "YES";
					return 0;
				}
				vis[to] = true;
				st.push(to);
			}
		}
		st.pop();
	}
	cout << "NO";

	return 0;
}