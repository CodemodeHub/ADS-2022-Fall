#include <bits/stdc++.h>
using namespace std;

int partition(int ar[], int left, int right) {
	int pivot = ar[right];
	int i = left;
	for (int j = left; j < right; j++) {
		if (ar[j] > pivot) {
			swap(ar[j], ar[i]);
			i++;
		}
	}
	swap(ar[i], ar[right]);
	return i;
}

void quicksort(int ar[], int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quicksort(ar, left, p - 1);
		quicksort(ar, p + 1, right);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ar[m][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[j][i];
		}
	}
	for (int i = 0; i < m; i++) {
		quicksort(ar[i], 0, n - 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ar[j][i] << " ";
		}
		cout << "\n";
	}
	return 0;
}