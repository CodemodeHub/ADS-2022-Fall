#include<bits/stdc++.h>
using namespace std;
int leftBound(int arr[], int n, int x) {
    int left = -1, right = n;
    while(right - left > 1) {
        int mid = (left + right) / 2;
        if(arr[mid] > x) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}
int rightBound(int arr[], int n, int x) {
    int left = -1, right = n;
    while(right - left > 1) {
        int mid = (left + right) / 2;
        if(arr[mid] > x) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}
int main() {
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a + n);
    cout<<endl;
    while(q--) {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int left1 = leftBound(a, n, l1);
        int right1 = rightBound(a, n, r1);
        int left2 = leftBound(a, n, l2);
        int right2 = rightBound(a, n, r2);
        if(right1 < left2) {
            cout<<right1 - left1 + right2 - left2<<endl; 
        } else {
            cout<<right2 - left1<<endl;
        }
        
    }
}