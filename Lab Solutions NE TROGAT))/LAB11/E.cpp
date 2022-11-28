#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > g;
vector<int> p;

int dsu_get(int v) {
	if (v == p[v]) {
		return v;
	} else {
		return p[v] = dsu_get(p[v]);
	}
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (a != b)
		p[a] = b;
}

int main() {

	int v, e;
	cin >> v >> e;
	p.resize(v);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g.push_back({ a, b });
	}

	for (int i = 0; i < v; ++i)
		p[i] = i;

	for (int i = 0; i < g.size(); ++i) {
		int a = g[i].first;
		int b = g[i].second;
		dsu_unite(a, b);
	}

	for (int i = 0; i < v; i++) { // V
		unordered_set<int> s;
		for (int j = i + 1; j < v; j++) { // (V - 1)
			s.insert(p[j]); // LogV
		}
		cout << s.size() << "\n";
	} // O(V^2 LogV)


	return 0;
}