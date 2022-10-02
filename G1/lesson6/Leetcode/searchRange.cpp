// TODO : DODELAT

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (target < nums[mid]) {
				right = mid - 1;
			} else if (target > nums[mid]) {
				left = mid + 1;
			} else {
				int l = mid, r = mid;
				while (nums[l] == nums[mid] && l >= 0) {
					l--;
				}
				while (nums[r] == nums[mid] && r < nums.size()) {
					r++;
				}
				// return {l - 1, r - 1};
				return { l + 1, r - 1 };
			}
		}
		return { -1, -1 };
	}
};