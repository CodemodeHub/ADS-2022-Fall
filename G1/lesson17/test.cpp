#include <bits/stdc++.h>
using namespace std;


bool comp(pair <pair < string, string >, double > p1,pair <pair < string, string >, double > p2){
    if(p1.second == p2.second){
        if(p1.first.first == p2.first.first){
            return p1.first.second < p2.first.second;
        }
        return p1.first.first < p2.first.first;
    }
    return p1.second < p2.second;
}



vector <pair <pair <string, string>, double > > merge(vector <pair <pair <string, string>, double > > a, vector <pair <pair <string, string>, double > > b) {
    vector <pair <pair <string, string>, double > > result;
    unsigned long long i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(comp(a[i], b[j])) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    while(j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;
}

vector <pair <pair <string, string>, double > >  merge_sort(vector <pair <pair <string, string>, double > > a, unsigned long long l, unsigned long long r) {
    if(l == r) {
        vector <pair <pair <string, string>, double > >  result;
        result.push_back(a[l]);
        return result;
    }
    unsigned long long m = l + (r - l) / 2;
    vector <pair <pair <string, string>, double > > left = merge_sort(a, l, m);
    vector <pair <pair <string, string>, double > >  right = merge_sort(a, m + 1, r);
    return merge(left, right);
}






int main(){
    unsigned long long n; cin >> n;
    string first, last;

    map <string, double> mp;

    mp["A+"] = 4.0;
    mp["A"] = 3.75;
    mp["B+"] = 3.50;
    mp["B"] = 3.00;
    mp["C+"] = 2.50;
    mp["C"] = 2.00;
    mp["D+"] = 1.50;
    mp["D"] = 1.00;
    mp["F"] = 0; 

    vector <pair <pair <string, string>, double > > v;

    for(unsigned long long i = 0; i < n; i++){
        cin >> first >> last;

        unsigned long long cnt; cin >> cnt;
        double x = 0;
        double y = 0;
        double itog = 0;
        while(cnt--){
            string grade;
            int cred;
            cin >> grade >> cred;
            x += mp[grade] * cred;
            y += cred;
        }
        itog = x / y;
        v.push_back(make_pair(make_pair(first, last), itog));
        
    }

    

    v = merge_sort(v, 0, v.size() - 1);
    cout << setprecision(3) << fixed;

    for(unsigned long long i = 0; i < v.size(); i++){
        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << endl;
    }
}