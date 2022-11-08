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

vector<string> disassemble(string s) {
	vector<string> res;
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
		} else if (s[i] == ' ' || i == s.size() - 1) {
			res.push_back(temp);
			temp = "";
		}
	}
	return res;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		string s;
		getline(cin, s);
		if (i == 0) continue;
		auto v = disassemble(s);
		auto v2 = merge_sort(v, 0, v.size() - 1);
		for (auto i : v2) cout << i << " ";
		cout << endl;
	}
	return 0;
}