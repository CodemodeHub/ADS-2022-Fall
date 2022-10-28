#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    if(x == 0 || x == 1)
        return false;
    for(int i = 2; i <= sqrt(x); i++)
        if(x % i == 0)
            return false;
    return true;
}

int main() {
    int n; cin>>n;
    // 10^5 
    
    for(int i = 2; i < n - 1; i++) {
        if(isPrime(i) && isPrime(n - i)) {
            cout<<i <<" " << n - i <<endl;
            break;
        }
    }
    // O(n sqrt(n))
}