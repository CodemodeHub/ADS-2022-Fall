#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin>>s[i];
    const int p = 31;
    vector<long long> p_pow (10000);
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;
    vector < pair<long long, int> > hashes (n);
    for (int i=0; i<n; ++i)
    {
        long long hash = 0;
        for (size_t j=0; j<s[i].length(); ++j)
            hash += (s[i][j] - 'a' + 1) * p_pow[j];
        hashes[i] = make_pair (hash, i);
    }

    sort (hashes.begin(), hashes.end());

    // выводим ответ
    for (int i=0, group=0; i<n; ++i)
    {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            cout << "\nGroup " << ++group << ":";
        cout << ' ' << s[hashes[i].second];
    }
    cout<<endl;
    return 0;
}

/*
abc
abc
cba
cas
abc
cba
->
1:
abc
abc
abc
2:
cba
cba
3:
cas

qwertyui
rty
*/