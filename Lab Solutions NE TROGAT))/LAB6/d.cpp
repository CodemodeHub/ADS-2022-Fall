#include <bits\stdc++.h>
using namespace std;

int partition(string& str, int left, int right) {
	int pivot = str[right];
	int i = left;
	for (int j = left; j < right; j++) {
		if (str[j] < pivot) {
			swap(str[j], str[i]);
			i++;
		}
	}
	swap(str[i], str[right]);
	return i;
}

void quicksort(string& str, int left, int right) {
	if (left < right) {
		int p = partition(str, left, right);
		quicksort(str, left, p - 1);
		quicksort(str, p + 1, right);
	}
}
int main() {
	int t, end, start;
	string str;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> str;
		end = str.size();
		quicksort(str, 0, end - 1);
		cout << str << "\n";
	}


	return 0;
}