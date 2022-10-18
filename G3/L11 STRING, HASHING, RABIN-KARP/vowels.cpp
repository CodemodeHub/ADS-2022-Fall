#include <iostream>
using namespace std;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

int partition(string& ar, int left, int right) {
	char pivot = ar[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (isVowel(ar[i]) && !isVowel(pivot)) {
			swap(ar[i], ar[index]);
			index++;
		} else if (!isVowel(ar[i]) && isVowel(pivot)) {
			continue;
		} else if (ar[i] < pivot) {
			swap(ar[i], ar[index]);
			index++;
		}

	}
	swap(ar[index], ar[right]);
	return index;
}

void quick_sort(string& ar, int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quick_sort(ar, left, p - 1);
		quick_sort(ar, p + 1, right);
	}
}

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;
	quick_sort(s, 0, n - 1);
	cout << s;
	return 0;
}