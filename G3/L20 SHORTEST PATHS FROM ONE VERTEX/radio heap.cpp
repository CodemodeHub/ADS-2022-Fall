#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int> > > g(n);
		vector<bool> used(n);
		const int INF = 1e9;
		vector<int> d(n, INF);
		k--;
		d[k] = 0;
		for (int i = 0; i < times.size(); i++) {
			times[i][0]--;
			times[i][1]--;
			g[times[i][0]].push_back({ times[i][1], times[i][2] });
		}

		priority_queue<pair<int, int> > q;
		q.push({ 0, k });
		while (!q.empty()) {
			pair<int, int> top = q.top();
			q.pop();
			int v = top.second;
			for (int i = 0; i < g[v].size(); i++) {
				int to = g[v][i].first;
				int cost = g[v][i].second;
				if (d[to] > d[v] + cost) {
					d[to] = d[v] + cost;
					q.push({ d[to], to });
				}
			}
		}



		int mx = -1;
		for (int i = 0; i < d.size(); i++) {
			mx = max(mx, d[i]);
		}
		if (mx == INF) return -1;
		return mx;
	}
};