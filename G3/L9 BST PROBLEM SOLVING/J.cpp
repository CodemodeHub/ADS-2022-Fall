#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void binary_search(int ar[], int left, int right) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		cout << ar[mid] << " ";
		binary_search(ar, mid + 1, right);
		binary_search(ar, left, mid - 1);
	}
}

int main() {
	int n;
	cin >> n;
	int size = pow(2, n) - 1;
	int ar[size];
	for (int i = 0; i < size; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + size);
	binary_search(ar, 0, size - 1);

	return 0;
}