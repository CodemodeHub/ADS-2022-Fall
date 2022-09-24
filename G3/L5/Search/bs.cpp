#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> v = {2, 2, 3, 5, 7, 8, 12, 15, 22, 22, 22, 234, 545, 1024};
	int target = 234;
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		// int mid = (left + right) / 2; BAD
		int mid = left + (right - left) / 2;
		if (target < v[mid])
		{
			right = mid - 1;
		}
		else if (target > v[mid])
		{
			left = mid + 1;
		} else {
			cout << mid;
			return 0;
		}
	}
	cout << -1;
	return 0;
}