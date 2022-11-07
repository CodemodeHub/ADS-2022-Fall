#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n, m;

vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    cin >> n ;
    g.resize(n);
    used.assign(n, false);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 0; j < x; j++) {
            int y; cin >> y;
            g[i].push_back(y);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 1) {
        cout<<"True\n";
    } else {
        cout<<"False\n";
    }
    return 0;
}