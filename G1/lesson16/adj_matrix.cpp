#include<iostream>
using namespace std;
int main() {
    int n; cin >> n; // number of vertices
    int m; cin >> m; // number of edges
    int adj[n][n];

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2; // v1 connected with v2
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
    
    return 0;
}