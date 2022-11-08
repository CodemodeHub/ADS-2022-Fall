#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int adj[N][N];
int n, m;

vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < n; i++) {
        if(i != v && adj[v][i] && !used[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    used.assign(n, false);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}

/*
1 1 0
1 1 0
0 0 1

0 -> 0, 1
1 -> 1, 0
2 -> 2

used[0] = true
used[1] = true
used[2] = false

*/