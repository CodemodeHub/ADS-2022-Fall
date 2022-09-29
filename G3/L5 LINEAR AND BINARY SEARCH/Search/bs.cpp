#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> v, int target)
{
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
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int binary_search_rec(vector<int> v, int target, int left, int right)
{
	if (left > right)
	{
		return -1;
	}
	int mid = left + (right - left) / 2;
	if (target < v[mid])
	{
		return binary_search_rec(v, target, left, mid - 1);
	}
	else if (target > v[mid])
	{
		return binary_search_rec(v, target, mid + 1, right);
	}
	else
	{
		return mid;
	}
}

int main()
{

	vector<int> v = {2, 2, 3, 5, 7, 8, 12, 15, 22, 22, 22, 234, 545, 1024};
	int target = 234;
	cout << binary_search(v, target);
	cout << endl;
	cout << binary_search_rec(v, target, 0, v.size() - 1);
	return 0;
}