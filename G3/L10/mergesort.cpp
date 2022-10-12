#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] <= right[r]) {
			result.push_back(left[l]);
			l++;
		} else {
			result.push_back(right[r]);
			r++;
		}
	}
	while (l < left.size()) {
		result.push_back(left[l]);
		l++;
	}
	while (r < right.size()) {
		result.push_back(right[r]);
		r++;
	}
	return result;
}

vector<int> mergeSort(vector<int> a, int l, int r) {
	if (l == r) {
		vector<int> res;
		res.push_back(a[l]);
		return res;
	}
	int m = l + (r - l) / 2;
	vector<int> left = mergeSort(a, l, m);
	vector<int> right = mergeSort(a, m + 1, r);
	return merge(left, right);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> sortedV = mergeSort(v, 0, n - 1);
	for (auto i : sortedV) {
		cout << i << " ";
	}
}