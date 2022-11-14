#include <bits\stdc++.h>
using namespace std;

bool comp(string s1, string s2) {
	string d = s1.substr(0, 2), m = s1.substr(3, 2), y = s1.substr(6, 4);
	string d2 = s2.substr(0, 2), m2 = s2.substr(3, 2), y2 = s2.substr(6, 4);

	if (y == y2) {
		if (m == m2) {
			return d < d2;
		}
		return m < m2;
	}
	return y < y2;
}

int partition(vector<string>& v, int left, int right) {
	string pivot = v[right];
	int i = left;
	for (int j = left; j < right; j++) {
		if (comp(v[j], pivot)) {
			swap(v[j], v[i]);
			i++;
		}
	}
	swap(v[i], v[right]);
	return i;
}

void quicksort(vector<string>& v, int left, int right) {
	if (left < right) {
		int p = partition(v, left, right);
		quicksort(v, left, p - 1);
		quicksort(v, p + 1, right);
	}
}
int main() {
	int t, end, start;
	string str;
	cin >> t;
	vector<string> v;
	for (int k = 0; k < t; k++) {
		cin >> str;
		v.push_back(str);
	}
	quicksort(v, 0, v.size() - 1);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}