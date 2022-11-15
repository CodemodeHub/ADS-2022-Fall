#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
    string prev_city; cin >> prev_city;
    prev_city[0] = tolower(prev_city[0]);
    int n; cin >> n;
    vector<string> result;
    int mx_len = 1;
    for(int i = 0; i < n; i++) {
        string city; cin >> city;
        city[0] = tolower(city[0]);
        string p = city + "#" + prev_city;
        vector<int> pi = prefix_function(p);
        city[0] = toupper(city[0]);
        if(pi.back() > mx_len) {
            mx_len = pi.back();
            result.clear();
            result.push_back(city);
        } else if(pi.back() == mx_len) {
            result.push_back(city);
        }
    }
    cout << result.size() << endl;
    for(string city: result)
        cout << city << endl;
    return 0;
}
/*
tauemel#kokshetau
t -> 0
ta -> 0 
tau -> 0
taue -> 0
tauem -> 0
taueme -> 0
tauemel -> 0
tauemel# -> 0
tauemel#k -> 0
tauemel#ko -> 0
tauemel#kok -> 0
tauemel#koks -> 0
tauemel#koksh -> 0
tauemel#kokshe -> 0
tauemel#kokshet -> 1
tauemel#koksheta -> 2
tauemel#kokshetau -> 3
*/