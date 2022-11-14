#include<bits/stdc++.h>
using namespace std;

string a, b;

vector<int> prefix_function (string s) {
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

bool check(int x) {
    string a1 = "";
    for(int i = 0; i < x; i++)
        a1 += a;
    string p = b + '#' + a1;
    vector<int> pi = prefix_function(p);
    for(int i = 0; i < pi.size(); i++)
        if(pi[i] == b.size())
            return true;
    return false;
}

int main() {
    cin >> a >> b;
    int l = 1, r = max(a.size(), b.size());
    bool ok = false;
    while(l < r) {
        int m = (l + r) / 2;
        if(check(m)) {
            ok = true;
            r = m;
        } else {
            l = m + 1;
        }
    }
    if(ok)
        cout << l << endl;
    else
        cout << - 1 << endl;
    return 0;
}
/*
a = abcd 
b = cdabcdab
m = 3
a1 = abcdabcdabcd
p = cdabcdab#abcdabcdabcd

*/