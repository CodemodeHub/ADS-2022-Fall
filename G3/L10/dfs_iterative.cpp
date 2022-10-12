class Solution {
public:
	int maxLevelSum(TreeNode* root) {
		vector<int> sums;
		int maxSum = INT_MIN, index = -1;
		stack<TreeNode*> st;
		st.push(root);
		int lvl = 0;
		while (!st.empty()) {
			int size = st.size();
			while (size--) {
				TreeNode* top = st.top();
				st.pop();
				if (lvl >= sums.size()) {
					sums.push_back(0);
				}
				sums[lvl] += top->val;
				if (top->right) st.push(top->right);
				if (top->left) st.push(top->left);
			}
			lvl++;
		}
		for (int i = 0; i < sums.size(); i++) {
			if (maxSum < sums[i]) {
				maxSum = sums[i];
				index = i + 1;
			}
		}
		return index;
	}