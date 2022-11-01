#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n);
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        v[v1 - 1].push_back(v2 - 1);
        v[v2 - 1].push_back(v1 - 1);
    }
    for(auto it: v) 
        cout<<it.size()<<" ";
    return 0;
}