#include <iostream>
using namespace std;

bool check(unsigned long long square_length, int x, int y) {
	return x <= square_length && y <= square_length;
}

bool count(unsigned long long a, int ar[][4], int n, int k) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (check(a, ar[i][2], ar[i][3])) cnt++;
	}
	return k <= cnt;
}

int main() {
	int n, k;
	cin >> n >> k;
	int ar[n][4];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> ar[i][j];
		}
	}

	unsigned long long left = 1, right = 1e10, mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (count(mid, ar, n, k)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}