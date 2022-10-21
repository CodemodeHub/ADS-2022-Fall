#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> left, vector<vector<int>> right) {
    int l = 0, r = 0;
    vector<vector<int>> result;
    while(l < left.size() && r < right.size()) {
        int left_sum = accumulate(left[l].begin(), left[l].end(), 0);
        int right_sum = accumulate(right[r].begin(), right[r].end(), 0); 
        if(left_sum < right_sum) {
            result.push_back(right[r]);
            r++;
        } else if (left_sum > right_sum) {
            result.push_back(left[l]);
            l++;
        }  else {
            for(int i = 0; i < left[l].size(); i++) {
                if(left[l][i] < right[r][i]) {
                    result.push_back(left[l]);
                    l++;
                    break;
                } else if (left[l][i] > right[r][i]) {
                    result.push_back(right[r]);
                    r++;
                    break;
                }
            }
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
vector<vector<int>> mergeSort(vector<vector<int>> a, int l, int r) {
    if(l == r) {
        vector<vector<int>> result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector<vector<int>> left = mergeSort(a, l, m);
    vector<vector<int>> right = mergeSort(a, m + 1, r);
    return merge(left, right);
}
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = vector<int>(m);
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> result = mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
