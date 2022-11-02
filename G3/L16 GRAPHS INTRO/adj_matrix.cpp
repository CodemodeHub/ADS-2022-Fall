#include <iostream>
using namespace std;

int main() {
	int m, n; // vertices and edges
	cin >> m >> n;
	int adj_matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			adj_matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj_matrix[u][v] = 1;
		adj_matrix[v][u] = 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << adj_matrix[i][j] << " ";
		}
		cout << "\n";
	}


	
	return 0;
}