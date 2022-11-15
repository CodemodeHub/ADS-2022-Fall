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
    string s, t; cin >> s >> t;
    string p = s + '#' + t;
    vector<int> pi = prefix_function(p);
    for(int p: pi)
        cout << p << " ";
    cout << endl;
    for(int i = 0; i < pi.size(); i++)
        if(pi[i] == s.size())
            cout << i - 2 * s.size() << " ";
    cout << endl;
    return 0;
}

/*
s = jax
t = ajaajaxjaxjaxadsafasf
p = jax#ajaajaxjaxjaxadsafasf
pi = {0 0 0 0 0 1 2 0 1 2 3 1 2 3 1 2 3 0 0 0 0 0 0 0 0}
10 13 16 - 2 * pattern.size() 
4, 7, 10
abcd 
cdabcdab

*/