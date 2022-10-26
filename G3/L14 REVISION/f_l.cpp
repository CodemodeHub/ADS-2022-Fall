class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int first = -1, last = -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				first = mid;
				r = mid - 1;
			} else if (target < nums[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (first == -1) {
			return { -1, -1 };
		}
		l = first, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				last = mid;
				l = mid + 1;
			} else if (nums[mid] < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return { first, last };
	}
};