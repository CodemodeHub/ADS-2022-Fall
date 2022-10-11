#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] < right[r]) {
            result.push_back(left[l]);
            l++;
        } else {
            result.push_back(right[r]);
            r++;
        }
    }
    while(l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while(r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    return result;
}

vector<int> merge_sort(vector<int> a, int l, int r) {
    if(l == r) {
        vector<int> result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector<int> left = merge_sort(a, l, m);
    vector<int> right = merge_sort(a, m + 1, r);
    return merge(left, right);
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<int> result = merge_sort(a, 0, n - 1);
    for(auto i: result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}