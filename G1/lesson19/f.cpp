#include<bits/stdc++.h>
using namespace std;
const int p = 31;
int main() {
    string s; cin >> s;
    int n = s.length();

    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p);

    vector<long long> pref_hashes(s.length() + 1, 0); // pref_hashes[i] = hash of s[0..i-1]
    for(int i = 0; i < s.length(); i++) {
        pref_hashes[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i > 0) pref_hashes[i] = (pref_hashes[i] + pref_hashes[i-1]);
    }

    unordered_set<long long> st;
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            long long cur_hash = pref_hashes[j];
            if(i > 0) cur_hash = (cur_hash - pref_hashes[i - 1]);
            cur_hash = (cur_hash * p_pow[n - i - 1]);
            st.insert(cur_hash);
        }
    }
    cout<<st.size();
    return 0;
}