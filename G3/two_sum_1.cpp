#include <iostream>
using namespace std;

int main()
{

	int nums[6] = {2, 6, 1, 12, 8, 4};
	int target = 5;
	// (2, 5)
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (i != j && nums[i] + nums[j] == target)
			{
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "NO RESULT";
	return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(n)