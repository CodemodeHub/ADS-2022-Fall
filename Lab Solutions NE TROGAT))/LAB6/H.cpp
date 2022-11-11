#include <bits/stdc++.h>
using namespace std;

int partition(vector<char>& ar, int left, int right) {
	int pivot = ar[right];
	int i = left;
	for (int j = left; j < right; j++) {
		if (ar[j] < pivot) {
			swap(ar[j], ar[i]);
			i++;
		}
	}
	swap(ar[i], ar[right]);
	return i;
}

void quicksort(vector<char>& ar, int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quicksort(ar, left, p - 1);
		quicksort(ar, p + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	vector<char> v;
	while (n--) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	quicksort(v, 0, v.size() - 1);
	char k;
	cin >> k;
	int l = 0, r = v.size() - 1;
	while (r - l > 0) {
		int mid = l + (r - l) / 2;
		if (k < v[mid]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (v[l] == v.back()) cout << v[0];
	else cout << v[r];
	// for (int i = 0; i < v.size(); i++) {
	// 	if (k < v[i]) {
	// 		cout << v[i];
	// 		return 0;
	// 	}
	// }
	// cout << v[0];
	return 0;
}

// O(NLogN + N) -> O((LogN + 1)N)
// O(NLogN + LogN) -> O((N + 1)LogN)