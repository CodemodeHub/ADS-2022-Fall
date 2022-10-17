#include<bits/stdc++.h>
using namespace std;
int main() {   
    string s;  int i1, i2, len; // входные данные
    cin>>s>>i1>>i2>>len;

    // считаем все степени p
    const int p = 31;
    // p[0] = p^0 = 1
    // p[1] = p^ 1 = 31
    // p[2] = p^2 = 961
    // p[3] = p^3 = 29791
    vector<long long> p_pow (s.length());
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;

    // считаем хэши от всех префиксов
    vector<long long> h (s.length());
    for (size_t i=0; i<s.length(); ++i)
    {
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if (i > 0)  h[i] += h[i-1];
    }
    /*
    string = 'qwerty'
    h[0] = hash('q')
    h[1] = hash('qw') = hash('w')(p=31) + h[0]
    h[2] = hash('qwe') = hash('e')(p=961) + h[1]
    h[3] = hash('qwer') = hash('r')(p=29791) + h[2]
    h[4] = hash('qwert') = hash('t')(p=923521) + h[3]
    h[5] = hash('qwerty') = hash('y')(p=28629151) + h[4]
    hash('ert') * p_pow[2] = h[4] - h[1]
    i1 = 2, len = 3
    h1 = h[2 + 3 - 1] = h[4] - h[2 - 1] = h[4] - h[1]
    */

    // получаем хэши двух подстрок
    long long h1 = h[i1+len-1]; // s = 'qweqwe', i1 = 0, len = 3, sub = 'qwe'
    if (i1)  h1 -= h[i1-1];
    long long h2 = h[i2+len-1]; // s = 'qweqwe', i2 = 3, len = 3, sub = 'qwe'
    if (i2)  h2 -= h[i2-1];
    /*
    s = qweqwe
    p_pow = {0: 1, 1: 31, 2: 961, 3: 29791, 4: 923521, 5: 28629151}
    hashes = {
        0('q') -> ('q' - 'a' + 1) * p_pow[0] = 16 * 1 = 16,
        1('qw') -> h[0] + ('w' - 'a' + 1) * p_pow[1] = 16 + 682 = 698
        2('qwe') -> h[1] + ('e' - 'a' + 1) * p_pow[2] = 698 + 4 *961 = 4542
        3('qwer') -> h[2] + ('r' - 'a' + 1) * p_pow[3] = 4542 + 17 * 29791 = 510989
    }
    h1 = hash('we') = (i = 1, len = 2) = h[2] - h[0] = 4542 - 16 = 4526
    h2 = hash('er') = (i = 2, len = 2) = h[3] - h[1] = 510989 - 698 = 510291
    h1 = h1 * p_pow[1] = 4526 * 31 = 140306
    */
    if(i1 < i2)
        h1 *= p_pow[i2 - i1];
    else 
        h2 *= p_pow[i1 - i2];
    
    // сравниваем их
    if (h1 == h2)
        cout << "equal\n";
    else
        cout << "different\n";   
}