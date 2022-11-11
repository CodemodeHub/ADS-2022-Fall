#include <bits/stdc++.h>
using namespace std;

map<string, double> m = {
	{"A+", 4.00},
	{"A", 3.75},
	{"B+", 3.50},
	{"B", 3.00},
	{"C+", 2.50},
	{"C", 2.00},
	{"D+", 1.50},
	{"D", 1.00},
	{"F", 0.00},
};

bool comp(pair<pair<string, string>, double>& p1, pair<pair<string, string>, double>& p2) {
	if (p1.second == p2.second) {
		if (p1.first.first == p2.first.first) {
			return p1.first.second < p2.first.second;
		}
		return p1.first.first < p2.first.first;
	}
	return p1.second < p2.second;
}

double calculateGpa(vector<pair<string, int> > v) {
	return 0.00;
}

int partition(vector<pair<pair<string, string>, double> > & v, int left, int right) {
	pair<pair<string, string>, double> pivot = v[right];
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

void quick_sort(vector<pair<pair<string, string>, double> >& v, int left, int right) {
	if (left < right) {
		int p = partition(v, left, right);
		quick_sort(v, left, p - 1);
		quick_sort(v, p + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	vector<pair<pair<string, string>, double> > v;
	while (n--) {
		vector<pair<string, int> > gpaV;
		string surname, name;
		int grades;
		cin >> surname >> name >> grades;
		while (grades--) {
			string mark;
			int credits;
			cin >> mark >> credits;
			gpaV.push_back({ mark, credits });
		}
		double gpa = calculateGpa(gpaV);
		v.push_back({{ surname, name }, gpa});
	}
}