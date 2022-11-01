#include <iostream>
using namespace std;
#define ull unsigned long long

bool check(ull a, ull b, ull c, ull n, ull mid) {
	ull cnt = mid / a + mid / b + mid / c;
	return cnt >= n;
}

int main() {
	ull n, a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	ull left = 0, right = 1e12 / 3;
	while (left < right) {
		ull mid = left + (right - left) / 2;
		if (check(a, b, c, n, mid)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	cout << left << " " << right;
}