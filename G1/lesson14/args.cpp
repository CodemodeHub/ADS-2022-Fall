#include<bits/stdc++.h>
using namespace std;
void transform(vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        a[i] += i;
}
int main() {
    // vector<int> a(10);
    int b[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << *(b + 5); // b[5];
    // for(auto i: a)
    //     cout<<i<<" ";
    // transform(a);
    // cout<<endl;
    // for(auto i: a)
    //     cout<<i<<" ";
    // cout<<endl;
    return 0;
}