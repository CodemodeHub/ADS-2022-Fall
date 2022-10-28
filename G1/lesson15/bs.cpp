#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[], int n, int target) {
    int l = 0, r = n - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(arr[m] == target) {
            return m;
        } else if(arr[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int target; cin >> target;
    cout<<binary_search(a, n, target);
    return 0;
}

/*
check(x) if(condition(x)) return true else false;
check(x) = true -> check(x + 1) -> true
check(x) = false -> check(x - 1) -> false
good(x)


l = 0, r = 1e9
l -> check(l) = false
r -> check(r) = true
while(l < r) {
    m = floor(l + r / 2)
    if(check(m))
        r = m
    else
        l = m + 1
-> max(good(l - 1) = false)
-> r = min(good(l|r) = true)

i -> 1 2 3 4 5 6 7 8 9
good(i) -> false, false, false, true, true, true, true, true, true

i -> 1 2 3 4 5 6 7 8 9
good(i) -> true, true, true, false, false, false, false, false, false
l = 0, r = 1e9
while(l < r) {
    m = ceil(l + r) / 2
    if(check(m))
        l = m
    else
        r = m - 1 

l = r -> check(l|r) = true
check(r + 1) = false

*/