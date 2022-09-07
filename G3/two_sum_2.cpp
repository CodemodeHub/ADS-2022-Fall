#include <iostream>
#include <map>
using namespace std;

int main()
{

	int nums[6] = {2, 6, 1, 12, 8, 4};
	int target = 5;
	// (2, 5)
	map<int, int> m;
	for (int i = 0; i < 6; i++) {
		if (m.find(target - nums[i]) != m.end()) {
			cout << i << ' ' << m[target - nums[i]] << endl;
			return 0;
		} else {
			m[nums[i]] = i;
		}
	}
	cout << "NO RESULT";
	return 0;
}

// Time complexity: O(n)
// Space complexity: O(n + m)

// {2:0, 6:1, 1:2, 12:3, 8:4}
// 5 - 2 = 3
// 5 - 6 = -1
// 5 - 1 = 4
// 5 - 12 = -7
// 5 - 8 = -3
// 5 - 4 = 1