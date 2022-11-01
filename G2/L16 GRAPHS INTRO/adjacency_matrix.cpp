#include <iostream>
using namespace std;

int main() {
	int m, n, x, y;
	cin >> m >> n;

	int adj_matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			adj_matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		// x--;
		// y--;
		adj_matrix[x][y] = 1;
		adj_matrix[y][x] = 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << adj_matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}