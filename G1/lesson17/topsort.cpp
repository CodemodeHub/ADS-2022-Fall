#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> ans;
void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
    ans.push_back(v);
}

int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    used.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++) 
        if(!used[i]) dfs(i);
    reverse(ans.begin(), ans.end());
    for(auto it: ans)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}