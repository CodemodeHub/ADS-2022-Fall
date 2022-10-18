#include<bits/stdc++.h>
using namespace std;
int main() {
    string s, t; // входные данные
    cin>>s>>t;

    // считаем все степени p
    const int p = 31;
    vector<long long> p_pow (max (s.length(), t.length()));
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;

    // считаем хэши от всех префиксов строки T
    vector<long long> h (t.length());
    for (size_t i=0; i<t.length(); ++i) {
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i)  h[i] += h[i-1];
    }

    // считаем хэш от строки S
    long long h_s = 0;
    for (size_t i=0; i<s.length(); ++i)
        h_s += (s[i] - 'a' + 1) * p_pow[i];

/*
s = qwe
t = qwertyuioqwe
*/
    // перебираем все подстроки T длины |S| и сравниваем их
    for (size_t i = 0; i + s.length() - 1 < t.length(); ++i) {
        long long cur_h = h[i+s.length()-1];
        if (i > 0)  cur_h -= h[i-1];
        // приводим хэши к одной степени и сравниваем
        if (cur_h == h_s * p_pow[i])
            cout << i << ' ';
    }
    return 0;
}