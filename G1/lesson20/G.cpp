#include<bits/stdc++.h>
using namespace std;

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

int main() {
    string s;
    cin >> s;
    vector<int> pi = prefix_function(s);
    cout << s.size() - pi.back() << endl;
    int counter = 0;
    for(int p: pi) {
        cout << p << " ";
        if(p == 0)
            counter++;
    }
    cout << counter << endl;
    return 0;
}