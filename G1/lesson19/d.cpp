#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<long long> powers(N);
const int p = 31;
const int q = 1e9 + 9;


void getPowers() {
    powers[0] = 1;
    for (int i = 1; i < N; i++)
        powers[i] = (powers[i - 1] * p); 
}

vector<long long> getPrefHashes(string s) {
    int n = s.length();
    vector<long long> hash(n);
    for (int i = 0; i < n; i++) {
        hash[i] = (s[i] - 'a' + 1) * powers[i];
        if(i) hash[i] += hash[i - 1];
    }
    return hash;
}

int search(string s, string t, vector<long long> h) {
    long long h_s = 0;

    for(int i = 0; i < s.length(); i++)
        h_s += (s[i] - 'a' + 1) * powers[i];

    int counter = 0;
    for (size_t i = 0; i + s.length() - 1 < t.length(); ++i){
        long long cur_h = h[i+s.length()-1];
        if (i)  cur_h -= h[i-1];
        if (cur_h == h_s * powers[i])
            counter++;
    }
    return counter;
}

int main() {
    int n;
    cin >> n;

    getPowers();

    while(n != 0) {
        vector<string> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        string s; cin >> s;
            
        vector<long long> prefHashes = getPrefHashes(s);
    
        vector<string> ans;
        int curMaxFrequency = 0;
        
        for(auto pattern: v) {

            int frequency = search(pattern, s, prefHashes);
            
            if(frequency > curMaxFrequency) {
                curMaxFrequency = frequency;
                ans.clear();
                ans.push_back(pattern);
            } else if(frequency == curMaxFrequency) {
                ans.push_back(pattern);
            }
        }
        cout<<curMaxFrequency<<endl;
        for(auto str: ans)
            cout << str << " ";
        cout<<endl;
        cin >> n;
    }
    return 0;
}