#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> component;

void dfs(int v) {
    used[v] = true;
    component.push_back(v);
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to] != true) {
            dfs(to);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    used.assign(n, false);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(used[i] != true) {
            component.clear();
            dfs(i);
            cout<<"Component:\n";
            for(auto vertex: component) 
                cout<<vertex<<" ";
            cout<<endl;
        }
    }
    return 0;
}