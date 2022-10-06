#include<iostream>
#include<cmath>
using namespace std;

bool check(int a[], int n, int x, int h) {
    int time = 0;
    for(int i = 0; i < n; i++) {
        time  += ceil(a[i] * 1.0 / x);
    }
    return time <= h;
}

int main() {
    int n, h;
    cin>>n>>h;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int l = 0, r = 1;
    while(!check(a, n, r, h))
        r *= 2;
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        if(check(a, n, m, h)) {
            r = m;
        } else {
            l = m;
        }
    } // O(n * log(h))
    cout<<r<<endl;
    return 0;
}