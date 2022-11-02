#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, cnt = 0;
	cin >> m;
	int matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt / 2;

}