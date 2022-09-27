class Solution
{
public:
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

	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][matrix[i].size() - 1] < target)
			{
				continue;
			}
			else
			{
				return binary_search(matrix[i], target) != -1;
			}
		}
		return false;
	}
};