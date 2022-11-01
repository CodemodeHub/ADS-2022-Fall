#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> used;
void dfs(int v) {
    used[v] = true;
    cout<<v<<" ";
    for(auto vertex: graph[v]) {
        if(!used[vertex])
            dfs(vertex);
    }
}
int main() {
    int n, m; cin>>n>>m;
    graph.resize(n);
    used.resize(n);
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 0; i < n; i++) {
        if(!used[i])
            dfs(i);
    }
}

/*

0: 4, 6, 1
1: 2, 0
2: 1, 4
3: 6, 5
4: 0, 5, 2
5: 4, 3
6: 0, 3

*/