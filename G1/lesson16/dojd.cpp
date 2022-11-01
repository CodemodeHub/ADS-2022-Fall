#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n; cin>>n;
    int adj[n][n];
    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>adj[i][j];
        }
    }
    for(int i = 0; i < n; i++)
        cin>>colors[i];
    int counter = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1 && colors[i] != colors[j]) {
                counter++;
            }
        }
    }
    cout<<counter / 2<<endl;
    return 0;
}
