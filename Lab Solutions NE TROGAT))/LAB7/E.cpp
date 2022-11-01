#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>& v1, vector<int>& v2) {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < v1.size(); i++) {
		sum1 += v1[i];
		sum2 += v2[i];
	}
	if (sum1 == sum2) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] < v2[i]) {
				return true;
			}
		}
	}

	return sum1 > sum2;
}

vector<vector<int> > merge(vector<vector<int> > left, vector<vector<int> > right) {
	vector<vector<int> > result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (comp(left[l], right[r])) {
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

vector<vector<int> > merge_sort(vector<vector<int> > a, int l, int r) {
	if (l == r) {
		vector<vector<int> > result;
		result.push_back(a[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<vector<int> > left = merge_sort(a, l, m);
	vector<vector<int> > right = merge_sort(a, m + 1, r);
	return merge(left, right);
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
	v = merge_sort(v, 0, v.size() - 1);
	cout << "\nCHECK\n";
	for (auto i : v) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}