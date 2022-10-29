#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			if (gcd(i, n / i) == 1) {
				cout << i << " " << n / i;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}