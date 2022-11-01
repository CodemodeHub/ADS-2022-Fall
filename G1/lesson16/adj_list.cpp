#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> graph;
// graph -> {}

int main() {
    int n; cin >> n; // number of vertices
    int m; cin >> m; // number of edges
    
    graph.resize(n);
    // graph -> {vector<int>, vector<int>, ... , vector<int>}

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    return 0;
}

/*
vector<int> v(n);
{0, 0, 0, 0, ... , 0}
int -> 0
float, double -> 0.0
string -> ""
bool -> False
char -> ''
vector<vector<int>> v(n);
{vector<int>, vector<int>}
v[0].size() -> 0
v[0].push_back()
*/