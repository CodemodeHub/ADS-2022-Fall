#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> states;
vector<int> p;
int cycle_start, cycle_end;

bool dfs(int v) {
    states[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(states[to] == 0) {
            p[to] = v;
            if(dfs(to)) return true;
        }
        else if(states[to] == 1) { 
            cycle_end = v;
            cycle_start = to;
            return true;
        }
    } 
    states[v] = 2;
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    p.assign(n, -1);
    g.resize(n);
    states.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    cycle_start = -1;
    for(int i = 0; i < n; i++) 
        if(dfs(i)) break;
    if(cycle_start == -1) {
        cout<<"Acyclic\n";
    } else {
        cout<<"Cycle:\n";
        vector<int> cycle;
        cycle.push_back(cycle_start);
		for (int v=cycle_end; v!=cycle_start; v=p[v])
			cycle.push_back(v);
		cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
		for (int i=0; i<cycle.size(); ++i)
            cout<<cycle[i]<<" ";
        cout<<endl;
    }
    return 0;
}