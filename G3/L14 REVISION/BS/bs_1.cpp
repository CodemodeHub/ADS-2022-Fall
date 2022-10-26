#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int target;
	cin >> target;
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
	}
	return 0;
}

/*
123456789
000001111
111110000

6
1 2 3 4 5 6 7 8 9 10
0 0 1 3 3 4 6 6 10 10

*/

// 7 / 2 -> 3
// (7 + 1) / 2 -> 4
// 1 2 3 4

/*

[1,2,5,9] 6
2 7
1 + 1 + 3 + 5 -> 10
1 + 1 + 1 + 2 -> 5
*/