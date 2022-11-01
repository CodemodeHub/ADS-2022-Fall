#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, string>& p1, pair<string, string>& p2) {
	return p1.first < p2.first;
}

int partition(vector<pair<string, string> >& v, int left, int right) {
	pair<string, string> pivot = v[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (comp(v[i], pivot)) {
			swap(v[i], v[index]);
			index++;
		}
	}
	swap(v[index], v[right]);
	return index;
}

void quick_sort(vector<pair<string, string> >& v, int left, int right) {
	if (left < right) {
		int p = partition(v, left, right);
		quick_sort(v, left, p - 1);
		quick_sort(v, p + 1, right);
	}
}

int main() {
	int n;
	vector<pair<string, string> > v;
	cin >> n;
	while (n--) {
		string oldname, newname;
		bool flag = false;
		cin >> oldname >> newname;
		for (int i = 0; i < v.size(); i++) {
			if (oldname == v[i].second) {
				v[i].second = newname;
				flag = true;
				break;
			}
		}
		if (!flag) {
			v.push_back({ oldname, newname });
		}
	}
	quick_sort(v, 0, v.size() - 1);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
}