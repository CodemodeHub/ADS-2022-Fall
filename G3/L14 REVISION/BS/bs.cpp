#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int target;
	cin >> target;
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == target) {
			cout << "FOUND\n";
			return 0;
		} else if (v[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	cout << "NOT FOUND\n";
	return 0;
}

/*
123456789
000001111
111110000
*/