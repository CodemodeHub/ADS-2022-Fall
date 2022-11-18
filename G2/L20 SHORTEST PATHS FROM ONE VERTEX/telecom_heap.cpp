#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int> > > g(n);
		vector<bool> used(n);
		vector<int> d(n, 1e9);
		for (int i = 0; i < times.size(); i++) {
			times[i][0]--;
			times[i][1]--;
			g[times[i][0]].push_back({ times[i][1], times[i][2] });
		}
		d[k - 1] = 0;

		priority_queue<pair<int, int> > q;
		q.push({ k - 1, 0 });
		while (!q.empty()) {
			pair<int, int> top = q.top();
			int v = top.first;
			int cur_d = -top.second;
			q.pop();
			if (cur_d > d[v]) continue;
			for (int j = 0; j < g[v].size(); j++) {
				int to = g[v][j].first;
				int cost = g[v][j].second;
				if (d[v] + cost < d[to]) {
					d[to] = d[v] + cost;
					q.push({ to, -d[to] });
				}
			}
		}

		int mx = -1;
		for (int i = 0; i < d.size(); i++) {
			mx = max(mx, d[i]);
		}
		if (mx == 1e9) return -1;
		return mx;
	}
};