#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n == 1 || n == 0) {
		return false;
	}
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
	int b = n - 2;
	while (true) {
		if (isPrime(a) && isPrime(b)) {
			cout << a << " " << b;
			return 0;
		}
		a++;
		b--;
	}
	// for (int i = 2; i <= n - 2; i++) {
	// 	if (isPrime(i) && isPrime(n - i)) {
	// 		cout << i << " " << n - i;
	// 		break;
	// 	}
	// }
	return 0;
}