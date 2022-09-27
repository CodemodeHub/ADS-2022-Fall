#include <iostream>
using namespace std;

int binary_search_inc(int ar[], int target, int n)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (target < ar[mid])
		{
			right = mid - 1;
		}
		else if (target > ar[mid])
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

int binary_search_dec(int ar[], int target, int n)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (target > ar[mid])
		{
			right = mid - 1;
		}
		else if (target < ar[mid])
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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	int a, b;
	cin >> a >> b;
	int ar2d[a][b];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> ar2d[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++) {
			if (j % 2 == 0) {
				int index = binary_search_dec(ar2d[j], ar[i], b);
				if (index != -1) {
					cout << j << " " << index << endl;
					break;
				} else if (index == -1 && j == a - 1) {
					cout << -1 << endl;
					break;
				}
			} else if (j % 2 == 1) {
				int index = binary_search_inc(ar2d[j], ar[i], b);
				if (index != -1)
				{
					cout << j << " " << index << endl;
					break;
				}
				else if (index == -1 && j == a - 1)
				{
					cout << -1 << endl;
					break;
				}
			}
		}
	}
	return 0;
}