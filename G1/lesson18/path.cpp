#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int adj[N][N];
vector<bool> used;
int n;

int minDistance(int from, int to) {
    queue<pair<int, int>> q;
    q.push(make_pair(from, 0));
    used[from] = true;
    while(!q.empty() && q.front().first != to) {
        int cur = q.front().first;
        int cur_distance = q.front().second;
        used[cur] = true;
        q.pop();
        for(int i = 0; i < n; i++)
            if(adj[cur][i] && !used[i])
                q.push(make_pair(i, cur_distance + 1));
    }
    if(q.empty())
        return -1;
    return q.front().second;
}

int main() {
    cin >> n;
    used.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            adj[i][j] = x;
        }
    }
    int a, b;
    cin >> a >> b;
    cout << minDistance(a - 1, b - 1) << endl;
    return 0;
}
/*
0 -> (0, 0)
q = {(1,1), (3, 1), (6, 1)}
1 -> {(3, 1), (6, 1), (2, 2), (4, 2)}
3 -> {((5, 3), (7, 3)}
#include<iostream> 
#include<queue> 
using namespace std; 
int main() { 
int n,i,j,k,f,s;queue<int> q; 
cin>>n;int a[n][n],d[n]; 
for(i=0;i<n;++i) { 
    d[i]=1000000000; 
    for(j=0;j<n;++j)
        cin>>a[i][j];
} 
cin>>s>>f;s--;f--; 
d[s]=0; q.push(s); 
while(!q.empty()){
    i=q.front();
    q.pop(); 
    for(j=0;j<n;++j) 
        if(a[i][j] && d[j] > d[i] + 1){ 
            d[j]=d[i]+1;
            q.push(j);
        }
} 
if(d[f]<1000000000)
    cout<<d[f]; 
else cout<<-1; 
return 0;
}
distances = {
    0 -> 0
    1 -> 1
    2 -> 2
    3 -> 1
    4 -> 3
    5 -> 2
}
q = {6, 2, 4}
*/