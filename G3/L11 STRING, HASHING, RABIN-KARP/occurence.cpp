class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.size() < needle.size()) return -1;
		vector<int> v = search(haystack, needle, 31);
		if (v.empty()) return -1;
		return v[0];
	}

	const int d = 26;
	vector<int> search(string s, string pattern, int q = 1e9 + 7) {
		int p = 0, t = 0, h = 1, i, j;
		vector<int> ans;
		for (i = 0; i < pattern.size() - 1; i++)
			h = (h * d) % q;

		for (i = 0; i < pattern.size(); i++) {
			p = (d * p + pattern[i]) % q;
			t = (d * t + s[i]) % q;
		}

		for (i = 0; i <= s.size() - pattern.size(); i++) {
			if (p == t) {
				for (j = 0; j < pattern.size(); j++) {
					if (s[i + j] != pattern[j]) break;
				}
				if (j == pattern.size()) {
					ans.push_back(i);
				}
			}

			if (i < s.size() - pattern.size()) {
				t = (d * (t - s[i] * h) + s[i + pattern.size()]) % q;
				if (t < 0) t += q;
			}
		}
		return ans;
	}
};