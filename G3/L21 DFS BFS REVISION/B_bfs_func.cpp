#include <bits/stdc++.h>
using namespace std;

int n, a, b;

void bfs(int** matrix) {
	if (a == b) {
		cout << 0;
		return;
	}
	int cnt = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		cnt++;
		int front = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (matrix[front][i] == 1) {
				if (i == b) {
					cout << cnt;
					return;
				}
				matrix[front][i] = 2;
				matrix[i][front] = 2;
				q.push(i);
			}
		}
	}
	cout << -1;
}

int main() {
	cin >> n;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> a >> b;
	a--; b--;

	bfs(matrix);

	return 0;
}