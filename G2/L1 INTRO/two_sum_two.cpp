vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> m;
	vector<int> answer(2);
	for (int i = 0; i < nums.size(); ++i) {
		if (m.find(target - nums[i]) != m.end()) {
			answer[0] = m[target - nums[i]];
			answer[1] = i;
			break;
		} else {
			m[nums[i]] = i;
		}
	}
	return answer;
}

// Time complexity: O(n)
// Space complexity: O(n + m)