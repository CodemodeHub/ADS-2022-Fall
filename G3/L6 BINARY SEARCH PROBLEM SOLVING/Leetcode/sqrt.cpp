class Solution
{
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		unsigned long long mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (mid * mid == x || ((mid + 1) * (mid + 1) > x && mid * mid < x)) {
				return mid;
			} else if (mid * mid > x) {
				right = mid - 1;
			} else if (mid * mid < x) {
				left = mid + 1;
			}
		}
		return -1;
	}
};