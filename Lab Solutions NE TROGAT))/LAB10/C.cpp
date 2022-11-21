#include <bits/stdc++.h>
using namespace std;

int main() {
	int rows, cols, mushrooms = 0, time = 0;
	cin >> rows >> cols;
	int matrix[rows + 2][cols + 2];
	vector<pair<int, int> > marios;
	for (int i = 0; i < rows + 2; i++) {
		for (int j = 0; j < cols + 2; j++) {
			if (i == 0 || j == 0 || i == rows + 1 || j == cols + 1) {
				matrix[i][j] = 1000;
				continue;
			}
			cin >> matrix[i][j];
			if (matrix[i][j] == 2) {
				marios.push_back({ i, j });
			} else if (matrix[i][j] == 1) {
				mushrooms++;
			}
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < marios.size(); i++) {
		q.push({ marios[i].first, marios[i].second });
	}
	while (!q.empty()) {
		if (!mushrooms) break;
		int size = q.size();
		while (size--) {
			pair<int, int> marioPos = q.front();
			q.pop();
			int i = marioPos.first;
			int j = marioPos.second;
			if (matrix[i - 1][j] == 1) {
				matrix[i - 1][j] = 2;
				q.push({ i - 1, j });
				mushrooms--;
			}
			if (matrix[i + 1][j] == 1) {
				matrix[i + 1][j] = 2;
				q.push({ i + 1, j });
				mushrooms--;
			}
			if (matrix[i][j - 1] == 1) {
				matrix[i][j - 1] = 2;
				q.push({ i, j - 1 });
				mushrooms--;
			}
			if (matrix[i][j + 1] == 1) {
				matrix[i][j + 1] = 2;
				q.push({ i, j + 1 });
				mushrooms--;
			}
		}
		time++;
	}
	cout << (!mushrooms ? time : -1);


	return 0;
}