

/*
 * Date:2021-06-02 21:08
 * filename:01_dp_count_the_paths.cpp
 *
 */
/*
 * 1-递推 (递归 + 记忆化)
 * 2-状态的定义 opt[n],dp[n],fib[n]
 * 3-状态转移方程 opt[n] = best_of(opt[n - 1],opt[n - 2],...)
 * 4-最优子结构
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *
int countPath(vector<vector<bool> >& grid, int row, int col) {
	if(!validSquare(grid, row, col)) return 0;
	if(isAtEnd(grid, row, col)) return 1;
	return countPath(grid, row + 1, col) + countPath(grid, row, col + 1);
}

*/

/*

https://stackoverflow.com/questions/27588652/count-number-of-paths-in-a-grid-using-dynamic-programming

*/


int countPath(vector<vector<int> >& vec,int m,int n) {
	int count[m][n];

	for(int i = 0; i < m;i++) {
		count[i][0] = 1;
	}

	for(int j = 0; j < n;j++) {
		count[0][j] = 1;
	}

	for(int i = 1;i < m;i++) {
		for(int j = 1;j < n;j++) {
			if(count[i][j] != 1) {
				count[i][j] = count[i - 1][j] + count[i][j - 1];
			}
			}
		}
	return count[m - 1][n - 1];
}

int main() {
	vector<vector<int> > obj = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	
	cout << countPath(obj,8,8) << endl;
	return 0;
}
