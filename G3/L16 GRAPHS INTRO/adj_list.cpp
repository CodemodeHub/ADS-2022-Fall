#include <iostream>
#include <vector>
using namespace std;
// int n; // 0
// string s; // ""
// float f; // 0.0
// vector<int> // {}
// vector<vector<int> > // {}

vector<vector<int> > g; // {}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m); // {{}, {}, {}, ... m}
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < g.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}