#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2) {
	return s1.size() <= s2.size();
}

vector<string> merge(vector<string> left, vector<string> right) {
	vector<string> result;
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

vector<string> merge_sort(vector<string> a, int l, int r) {
	if (l == r) {
		return { a[l] };
	}
	int m = l + (r - l) / 2;
	vector<string> left = merge_sort(a, l, m);
	vector<string> right = merge_sort(a, m + 1, r);
	return merge(left, right);
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		vector<string> v;
		string s, t;
		getline(cin, s);
		stringstream ss(s);
		while (getline(ss, t, ' ')) {
			v.push_back(t);
		}
		if (i == 0) continue;

		auto v2 = merge_sort(v, 0, v.size() - 1);
		for (auto i : v2) cout << i << " ";
		cout << endl;
	}
	return 0;
}