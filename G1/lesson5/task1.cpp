#include<iostream>
using namespace std;
int main() {
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x; // i -> min a[i] >= x
    int l = -1, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (a[m] > x) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}