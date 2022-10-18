class Solution {
public:
	int isPrefixOfWord(string sentence, string searchWord) {
		sentence += " ";
		vector<string> words;
		string temp = "";
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == ' ') {
				words.push_back(temp);
				temp = "";
			} else {
				temp += sentence[i];
			}
		}
		for (int i = 0; i < words.size(); i++) {
			if (words[i].size() < searchWord.size()) {
				continue;
			}
			vector<int> indices = search(words[i], searchWord, 31);
			if (!indices.empty()) {
				if (indices[0] == 0) {
					return i + 1;
				}
			}
		}
		return -1;
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