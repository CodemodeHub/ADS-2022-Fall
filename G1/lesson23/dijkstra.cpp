#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> g;

int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back(make_pair(b, w));
    }
    int start, end; cin >> start >> end;
    vector<int> d(n, INF);
    d[start] = 0;
    vector<bool> used(n);
    for(int i = 0; i < n; i++) {
        int v = -1;
        for(int j = 0; j < n; j++)
            if(!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if(d[v] == INF) break;
        used[v] = true;
        for(int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first, 
                cost = g[v][j].second;
            if(d[v] + cost < d[to])
                d[to] = d[v] + cost;
        }
    }
    cout << d[end] << endl;
    return 0;
}