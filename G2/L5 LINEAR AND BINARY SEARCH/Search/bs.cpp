#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> array, int target)
{
	int left = 0;
	int right = array.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (array[mid] == target)
		{
			return mid;
		}
		else if (array[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int binary_search_rec(vector<int> array, int target, int left, int right) {
	if (left > right) {
		return -1;
	}
	int mid = left + (right - left) / 2;
	if (array[mid] == target) {
		return mid;
	} else if (target < array[mid]) {
		return binary_search_rec(array, target, left, mid - 1);
	} else {
		return binary_search_rec(array, target, mid + 1, right);
	}
}

int main() {

	vector<int> v = {1, 2, 2, 6, 6, 8, 9, 12, 15, 235, 555, 1000, 1000, 2000};
	int target = 555;
	cout << binary_search(v, target) << endl;
	cout << binary_search_rec(v, target, 0, v.size() - 1);
	return 0;
}