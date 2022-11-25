#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {


	int m, n;
	cin >> m >> n;
	int d[m][m];
	vector<vector<int> > p(m);
	for (int i = 0; i < m; i++) {
		p[i].assign(m, -1);
	}

	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << p[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				d[i][j] = 0;
			} else {
				d[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		d[u][v] = w;
		p[u][v] = u;
	}
	int start = 0, end = 2;

	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
		}
	}
	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << p[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }
	// vector<int> path;
	// for (int i = end; i != -1; i = p[start][i]) {
	// 	path.push_back(i);
	// }
	// for (int i = path.size() - 1; i >= 0; i--) {
	// 	cout << path[i] + 1 << ' ';
	// }


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << d[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}

// 1. BFS - min dist in unweighted graph
// O(V + E)
// 2. Dijkstra - greedy algorithm, WEIGHTED GRAPH, from single - source
// O(V ^ 2 * E)
// optimised dijkstra - O(V * E * logV)
// 3. Ford - Bellman - WEIGHTED GRAPH, from single - source
// O(V * E)
// 4. Floyd - Warshall - WEIGHTED GRAPH, from any vertex to any vertex;
// O(V ^ 3)