#include <iostream>
#include <algorithm>
using namespace std;

bool torkaet(pair<int, double> p, int k) {
	return int(p.first * p.second) >= k;
}

bool comp(pair<int, double> p1, pair<int, double> p2) {
	if (p1.first * p1.second == p2.first * p2.second) {
		return p1.first < p2.first;
	}
	return p1.first * p1.second < p2.first* p2.second;
}

int binary_search(pair<int, double> ar[], int n, int k) {
	int left = 0, right = n - 1, mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (torkaet(ar[mid], k)) {
			right = mid - 1;
		} else if (!torkaet(ar[mid], k)) {
			left = mid;
		}
	}
	return left;
}

int main() {

	int n, x, k;
	double y;
	cin >> n >> k;
	pair<int, double> ar[n];
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		ar[i] = { x, y };
	}
	sort(ar, ar + n, comp);
	int i = binary_search(ar, n, k);
	cout << ar[i].first << " " << ar[i].second;
	return 0;
}
