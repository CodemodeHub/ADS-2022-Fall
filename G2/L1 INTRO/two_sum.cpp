#include <iostream>
using namespace std;

int main()
{

	int array[6] = {1, 0, -5, 4, 11, 3};
	int target = 15;
	// answer: (3, 4)
	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			if (i != j && array[i]+array[j] == target) {
				cout << i << " " << j << endl;
				return;
			}
		}
	}
	cout << "NO SOLUTION";
	// Time complexity: O(n^2)
	// Space complexity: O(n)
	return 0;
}