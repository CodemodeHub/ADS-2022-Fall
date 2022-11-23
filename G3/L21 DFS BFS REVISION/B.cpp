#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, a, b;
	cin >> n;
	int matrix[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> a >> b;
	a--; b--;

	// BFS	
	// 1. vector<bool>; 2. matrix[i][j] = 2
	if (a == b) {
		cout << 0;
		return 0;
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
					return 0;
				}
				matrix[front][i] = 2;
				matrix[i][front] = 2;
				q.push(i);
			}
		}
	}
	cout << -1;


	return 0;
}