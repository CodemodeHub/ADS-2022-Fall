#include <iostream>
using namespace std;

bool check(int n, int mid) {
	return mid * mid <= n && (mid + 1) * (mid + 1) > n;
}

int main() {
	int n;
	cin >> n;
	int left = 0, right = n;
	while (right - left > 0) {
		int mid = left + (right - left) / 2;
		if (check(n, mid)) {
			cout << mid;
			return 0;
		} else if (mid * mid > n) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
}