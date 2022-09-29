#include <iostream>
using namespace std;

int binary_search_inc(int ar[], int target, int size)
{
	int left = 0, right = size - 1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
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

int binary_search_dec(int ar[], int target, int size)
{
	int left = 0, right = size - 1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
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
	int n;
	cin >> n;
	int numbers[n];
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	int a, b;
	cin >> a >> b;
	int matrix[a][b];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			int index;
			if (j % 2 == 0)
			{
				index = binary_search_dec(matrix[j], numbers[i], b);
			}
			else
			{
				index = binary_search_inc(matrix[j], numbers[i], b);
			}
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

	return 0;
}