#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	unsigned long long left = 0, right = 1e15, mid, cnt, sum;
	while (left < right) {
		mid = left + (right - left) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < sum + ar[i]) {
				sum = 0;
				cnt++;
			}
			if (mid < ar[i]) {
				cnt = k + 1;
			}
			sum += ar[i];
		}
		if (cnt > k) {
			left = mid + 1;
		} else if (cnt <= k) {
			right = mid;
		}
	}
	cout << left;
	return 0;
}