#include<bits/stdc++.h>
using namespace std;
const int p = 31;
const int q = 1e9 + 7;
int main() {
    string s;
    cin >> s;

    vector<long long> p_pow(s.length()); // p_pow[i] = p^i
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % q;
    /*
        p = 31
        p_pow = {
            0 -> 1
            1 -> p_pow[1 - 1] * p % q = 1 * 31 % 1000000007 = 31
            2 -> p_pow[2 - 1] * p % q = 31 * 31 % 1000000007 = 961
            3 -> p_pow[3 - 1] * p % q = 961 * 31 % 1000000007 = 29791
            4 -> p_pow[4 - 1] * p % q = 29791 * 31 % 1000000007 = 923521
            5 -> p_pow[5 - 1] * p % q = 923521 * 31 % 1000000007 = 28629151
            6 -> p_pow[6 - 1] * p % q = 28629151 * 31 % 1000000007 = 887503681
        }
        s1 = "code"
        s2 = "odec"
        s1.substr(1, 3) = "ode"
        h1 = hash[1..3] = pref_hashes1[3](p^3) - pref_hashes1[0] 
        s2.substr(0, 2) = "ode"
        h2 = hash[0..2] = pref_hashes2[2](p^2)) 
        pref[0] = c
        pref[1] = co
        pref[2] = cod
        pref[3] = code
        pref_hashes[0] = (s[i] - 'a' + 1) * p_pow[i] % q = 3 * 1 % 1000000007 = 3
        pref_hashes[1] = (s[i] - 'a' + 1) * p_pow[i] % q = 15 * 31 % 1000000007 = 465 + pref_hashes[0] = 465 + 3 = 468
        pref_hashes[2] = (s[i] - 'a' + 1) * p_pow[i] % q = 4 * 961 % 1000000007 = 14415 + pref_hashes[1] = 14415 + 468 = 14883
        pref_hashes[3] = (s[i] - 'a' + 1) * p_pow[i] % q = 5 * 29791 % 1000000007 = 148955 + pref_hashes[2] = 148955 + 14883 = 163838
    */
    vector<long long> pref_hashes(s.length() + 1, 0); // pref_hashes[i] = hash of s[0..i-1]
    for(int i = 0; i < s.length(); i++) {
        pref_hashes[i] = (s[i] - 'a' + 1) * p_pow[i] % q;
        if(i > 0) pref_hashes[i] = (pref_hashes[i] + pref_hashes[i-1]) % q;
    }

    return 0;
}