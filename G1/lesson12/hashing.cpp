#include<bits/stdc++.h>
using namespace std;
int main() {
    const int p = 31;
    const int q = 1e9 + 9;
    long long hash = 0, p_pow = 1;
    string s;
    cin>>s;
    for (size_t i=0; i<s.length(); ++i) {
        // желательно отнимать 'a' от кода буквы
        // единицу прибавляем, чтобы у строки вида 'aaaaa' хэш был ненулевой
        hash += ((s[i] - 'a' + 1) * p_pow) % q;
        p_pow *= p;
    }
    cout<<hash<<endl;
}
/*
abc
hash = 0
1) s[i] = 'a' -> val = 1 -> hash = 0 + 1 * 1 = 1
hash = 1, p_pow = 31
2) s[i] = 'b -> val = 2 -> hash = 1 + 2 * 31 = 63
hash = 63, p_pow = 961
3) s[i] = 'c -> val = 3 -> hash = 63 + 3 * 961 = 2946
*/