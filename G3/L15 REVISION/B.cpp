#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i < int(sqrt(n)) + 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int a = 2;
	while (true) {
		int b = n - a;
		if (isPrime(a) && isPrime(b)) {
			cout << a << " " << b;
			return 0;
		}
		a++;
	}
	return 0;
}