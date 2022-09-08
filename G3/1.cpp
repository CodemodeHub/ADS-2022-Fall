#include <iostream>
using namespace std;

int main() {

	int n = 2022;
	int* p = &n;
	int **pp = &p;
	// p - some address in memory: e.g. 0x61fe14
	// *p - encapsulated value: e.g. 2022
	cout << n << endl;
	cout << p << endl;
	cout << pp << endl;
	return 0;
}