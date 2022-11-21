#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0, n, a, b;
	cin >> n;
	int matrix[n][n];
	vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> a >> b;
	a--; b--;

	if (a == b) {
		cout << cnt;
		return 0;
	}
	queue<int> q;
	q.push(a);
	visited[a] = true;
	while (!q.empty()) {
		int u = q.front();
		cnt++;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && matrix[u][i]) {
				if (i == b) {
					cout << cnt;
					return 0;
				}
				visited[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
	cout << -1;

	return 0;
}