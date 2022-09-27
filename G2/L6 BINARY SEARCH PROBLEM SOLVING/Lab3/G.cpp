#include <iostream>
using namespace std;

int binary_search(int ar[], int size, int flights) {
	int max_number = 0;
	for (int i = 0; i < size; i++) {
		max_number = max(max_number, ar[i]);
	}
	int left = 1, right = max_number, mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		int req_flights = 0;
		for (int i = 0; i < size; i++) {
			req_flights += (ar[i] + mid - 1) / mid;
		}
		if (req_flights < flights) {
			right = mid - 1;
		} else if (req_flights > flights) {
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return left;
}

int main() {
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	cout << binary_search(ar, n, k);
	return 0;
}