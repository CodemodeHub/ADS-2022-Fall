#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int target; cin>>target;
    int left = 0, right = n - 1;
    bool found = false;
    while(left < right) {
        int middle = left + (right - left) / 2;
        if(arr[middle] == target) {
            found = true;
            break;
        } else if(arr[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    if(found) cout<<"Found\n";
    else cout<<"Not found\n";
    return 0;
}

/*
First bad version
0 0 0 0 0 0 0 0 
value = good -> value + 1 = good
value = bad -> value - 1 = bad
bool check() {

}
while(l < r) {

}
check(l - 1) -> false
check(l/r) -> true
123456789
000001111 = false ->true (minimal proper answer)
left = 0, right = 1
while(!check(right))
    right *= 2
111110000 = true -> false (maximal proper answer)
2) check(l/r) -> true
check(l + 1/r + 1) -> false


check()
check(left) -> false
check(right) -> true 
while(r - l > 1) -> 
l = max(check(x) == false)
r = min(check(x) == true)

*/