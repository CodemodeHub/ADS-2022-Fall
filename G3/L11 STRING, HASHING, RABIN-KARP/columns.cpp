#include <iostream>
using namespace std;

int partition(int ar[], int left, int right) {
	int pivot = ar[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (ar[i] < pivot) {
			swap(ar[i], ar[index]);
			index++;
		}
	}
	swap(ar[index], ar[right]);
	return index;
}

void quick_sort(int ar[], int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quick_sort(ar, left, p - 1);
		quick_sort(ar, p + 1, right);
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	int ar[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}