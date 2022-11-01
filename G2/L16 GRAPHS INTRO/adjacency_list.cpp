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
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < g.size(); i++) {
		cout << i << " vertices:";
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

// {}
// {vector<int>, vector<int>, vector<int>, ... m};