#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;
	int matrix[n][q];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		cout << (matrix[a][b] && matrix[a][c] && matrix[b][c] ? "YES\n" : "NO\n");
	}

	return 0;
}