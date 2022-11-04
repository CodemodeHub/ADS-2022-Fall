#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> colors;

int main() {
	int m;
	cin >> m;
	colors.resize(m);
	int matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> colors[i];
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (matrix[i][j] == 1) {
				if (colors[i] != colors[j]) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}