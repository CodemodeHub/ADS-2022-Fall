#include <iostream>
using namespace std;

int binary_search_inc(int ar[], int target, int left, int right) {
	if (right < left) {
		return -1;
	}
	int mid = left + (right - left) / 2;
	if (target < ar[mid]) {
		return binary_search_inc(ar, target, left, mid - 1);
	} else if (target > ar[mid]) {
		return binary_search_inc(ar, target, mid + 1, right);
	} else {
		return mid;
	}
}

int binary_search_dec(int ar[], int target, int left, int right) {
	if (right < left) {
		return -1;
	}
	int mid = left + (right - left) / 2;
	if (target < ar[mid]) {
		return binary_search_inc(ar, target, mid + 1, right);
	} else if (target > ar[mid]) {
		return binary_search_inc(ar, target, left, mid - 1);
	} else {
		return mid;
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x;
	cin >> x;
	int ar[x];
	for (int i = 0; i < x; i++) {
		cin >> ar[i];
	}
	int m, n;
	cin >> m >> n;
	int ar2d[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ar2d[i][j];
		}
	}

	for (int k = 0; k < x; k++) {
		for (int i = 0; i < m; i++) {
			if (i % 2 == 0) {
				int index = binary_search_dec(ar2d[i], ar[k], 0, n - 1);
				if (index != -1)
				{
					cout << i << " " << index << endl;
					break;
				}
				else if (index == -1 && i == m - 1)
				{
					cout << index << endl;
				}
			} else {
				int index = binary_search_inc(ar2d[i], ar[k], 0, n - 1);
				if (index != -1)
				{
					cout << i << " " << index << endl;
					break;
				}
				else if (index == -1 && i == m - 1)
				{
					cout << index << endl;
				}
			}
		}
	}

	return 0;
}