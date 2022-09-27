class Solution
{
public:
	int firstBadVersion(int n)
	{
		int left = 1, right = n;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid))
			{
				right = mid;
			}
			else if (!isBadVersion(mid))
			{
				left = mid + 1;
			}
		}
		return right;
	}
};

class Solution
{
public:
	int firstBadVersion(int n)
	{
		int left = 1, right = n, ans;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid))
			{
				ans = mid;
				right = mid - 1;
			}
			else if (!isBadVersion(mid))
			{
				left = mid + 1;
			}
		}
		return ans;
	}
};