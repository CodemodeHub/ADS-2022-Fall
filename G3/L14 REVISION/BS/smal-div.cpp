class Solution {
public:
	bool check(int mid, vector<int>& nums, int threshold) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += ceil(double(nums[i]) / double(mid));
		}
		return sum <= threshold;
	}

	int smallestDivisor(vector<int>& nums, int threshold) {
		int left = 1, right = 1e6;
		while (right - left >= 1) {
			int mid = left + (right - left) / 2;
			if (check(mid, nums, threshold)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return right;
	}
};