#include <iostream>
using namespace std;

bool isVowel(char c) {
	string s = "aeiouAEIOU";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == c) {
			return true;
		}
	}
	return false;
}

int countVowels(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isVowel(s[i])) cnt++;
	}
	return cnt;
}

int partition(string ar[], int left, int right) {
	string pivot = ar[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (countVowels(ar[i]) < countVowels(pivot)) {
			swap(ar[i], ar[index]);
			index++;
		} else if (countVowels(ar[i]) > countVowels(pivot)) {
			continue;
		} else if (ar[i] < pivot) {
			swap(ar[i], ar[index]);
			index++;
		}
	}
	swap(ar[index], ar[right]);
	return index;
}

void quick_sort(string ar[], int left, int right) {
	if (left < right) {
		int p = partition(ar, left, right);
		quick_sort(ar, left, p - 1);
		quick_sort(ar, p + 1, right);
	}
}

int main() {
	string ar[] = {
		"Alikh",
		"Lyaka",
		"Nurbekushka",
		"MirASS",
		"Amanback",
		"Iyeesha",
		"Adema",
		"Danik",
		"Dinara_Aktau_NIS",
		"Aldick",
		"Darinchick",
		"Erdogan",
		"Ayazhan",
		"Beka",
		"Nurs",
		"Alina",
		"Aruzhan",
		"Artem_Nexia",
		"Akmira",
		"Yerkezhan",
		"Yeldana",
		"Sam",
		"Bakdaulet",
		"Zhako",
		"Batyr",
		"Julia",
		"Zhadyra",
		"Amirchik",
		"Temir",
		"Manas",
		"Amina",
		"Aibergen",
		"Lera",
		"Bauka srauka",
		"Jax Cobalt sexy boy 2002"
	};
	int n = sizeof(ar) / sizeof(ar[0]);
	quick_sort(ar, 0, n - 1);
	for (auto i : ar) {
		cout << i << endl;
	}
	return 0;
}