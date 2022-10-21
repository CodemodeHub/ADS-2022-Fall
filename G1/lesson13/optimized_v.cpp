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
/*
s = "abcabca"
pi = {0,0,0,1,2,3,4}
pi[0] = 0
1)  i = 1
    j = pi[i - 1] = pi[1 - 1] = pi[0] = 0
    s[i] = s[1] = 'b'
    s[j] = s[0] = 'a'
    pi[1] = 0
2) i = 2
    j = pi[1] = 0
    s[i] = s[2] = 'c'
    s[j] = s[0] = 'a'
    pi[2] = 0
3) i = 3
    j = pi[2] = 0
    s[i] = s[3] = 'a'
    s[j] = s[0] = 'a'
    j -> 1
    pi[3] = 1
4) i = 4
    j = pi[3] = 1
    s[i] = s[4] = 'b'
    s[j] = s[1] = 'b'
    while(j > 0 && 'b' != 'b')
        j = pi[j - 1] = pi[1 - 1] = 0
    j -> 2
    pi[4] = 2
5) i = 5
    j = pi[4] = 2
    s[i] = s[5] = 'c'
    s[j] = s[2] = 'c'
    j -> 3
    pi[5] = 3
6) i = 6
    j = pi[5] = 3
    s[i] = s[6] = 'a'
    s[j] = s[3] = 'a'
    j -> 4
    pi[6] = 4

i = 3
pi[i] = n
pi[i + 1] - 1 <= pi[i]

*/

