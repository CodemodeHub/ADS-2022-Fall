#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, u, v, cnt = 0;
	cin >> n;
	int matrix[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> u >> v;
	u--; v--;
	queue<int> q;
	q.push(u);
	// matrix[u][u] = 0;
	while (!q.empty()) {
		cnt++;
		int front = q.front();
		for (int i = 0; i < n; i++) {
			if (matrix[front][i] == 1) {
				matrix[front][i] = 0;
				matrix[i][front] = 0;
				if (i == v) {
					cout << cnt;
					return 0;
				}
				q.push(i);
			}
		}
		q.pop();
	}
	cout << -1;

	return 0;
}