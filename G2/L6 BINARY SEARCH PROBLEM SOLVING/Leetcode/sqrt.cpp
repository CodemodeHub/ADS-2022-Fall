class Solution
{
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		unsigned long long mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (mid * mid == x || ((mid * mid) < x && (mid + 1) * (mid + 1) > x)) {
				return mid;
			} else if (mid * mid < x) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return left;
	}
};