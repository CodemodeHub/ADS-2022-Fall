/*
3
asas 3
asasasasasas -> 12
asasasas -> 8
aaa 1
aaa -> 3
b 2
bb -> 2
nugman 7
nugmannugmannugmannugmannugmannugmannugman -> 42
nugmanugmanugmanugmanugmanugmanugman -> 36
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s) { // O
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    vector<int> pi = prefix_function(s);
    int suff_size = pi.back();
    int to_add = s.size() - suff_size;
    int result = 0;
    while(--k)
        result += to_add;
    cout << result << endl;
    return 0;
}