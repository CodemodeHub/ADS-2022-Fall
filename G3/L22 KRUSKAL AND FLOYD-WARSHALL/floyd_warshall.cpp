#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {

	int m, n;
	cin >> m >> n;
	int d[m][m];
	vector<vector<int> > p(m);
	for (int i = 0; i < m; i++) {
		p[i].assign(m, -1);
	}

	int start, end;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		d[u][v] = w;
		p[u][v] = u;
	}
	cin >> start >> end;
	start--; end--;

	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
				// d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}

	vector<int> path;
	for (int i = end; i != -1; i = p[start][i]) {
		path.push_back(i);
	}
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] + 1 << ' ';
	}


	return 0;
}