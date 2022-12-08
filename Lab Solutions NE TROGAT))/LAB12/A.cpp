#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, x;
	cin >> n;
	int d[n][n];
	set<int> toIgnore; // тут ноды которые игнорим
	for (int i = 0; i < n; i++) {
		toIgnore.insert(i); // по дефолту все ноды игнорим
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	
	for (int q = 0; q < n; q++) {
		cin >> x;
		x--;
		toIgnore.erase(x); // ноду Х терь не игнорим
		int ans = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (toIgnore.find(i) != toIgnore.end()) continue; // если игнорим i то скип
				for (int j = 0; j < n; j++) {
					if (toIgnore.find(j) != toIgnore.end()) continue; // если игнорим j то скип
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) { // тут ищем длиннейший кратчайший путь
			if (toIgnore.find(i) != toIgnore.end()) continue; // если игнорим i то скип
			for (int j = 0; j < n; j++) {
				if (toIgnore.find(j) != toIgnore.end()) continue; // если игнорим j то скип
				ans = max(ans, d[i][j]); // конкретно вот
			}
		}
		cout << ans << "\n";
	}

	return 0;
}