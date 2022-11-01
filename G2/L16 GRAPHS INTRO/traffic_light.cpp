#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < g.size(); i++) {
		cout << g[i].size() << " ";
	}
	return 0;
}