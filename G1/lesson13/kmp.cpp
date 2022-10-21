#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
    // O(n)
	return pi;
}
vector<int> findSubstrings(string txt, string pat) {
	vector<int> ans;
	string concat = pat + '#' + txt;
	vector<int> pi = prefix_function(concat); // O(N)
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			ans.push_back(i - 2 * pat.size());
		}
	}
	return ans;
}
int main() {
    string s = "abc";
    string text = "adfsghjklkfdgfxgvbnmaabcbavabcabcagkjh,fashvkfjaslhkaavavasvsavasfafasfsafsafsafsafsafasfafasfaslglj;sal;gabcagelj'ahlj'ah'ljaehlj'ahel'l'ahal'hl'jagl'aabcabc";
    vector<int> ans = findSubstrings(text, s);
    for(auto i: ans) 
        cout<<i<<" ";
    cout<<endl;
    return 0;
}