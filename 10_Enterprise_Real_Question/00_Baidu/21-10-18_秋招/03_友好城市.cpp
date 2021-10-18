

/*
 * Date:2021-10-18 20:28
 * filename:03_友好城市.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> res;
	int temp1;

	for (int i = 0; i < m;i++) {
		for (int j = 0; j < 2;j++) {
			scanf("%d", &temp1);
			res[i][j] = temp1;
		}
	}
	
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < 2;j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
