

/*
 * Date:2022-01-04 21:31
 * filename:200_number-of-islands_岛屿数量.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

namespace jike {
	class Solution {
		public: 
			int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

			bool DFS(vector<vector<char>>& grid, int x, int y) {
				int m = grid.size(), n = grid[0].size();
				if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
					return false;
				}
				grid[x][y] = '0';
				bool flag = true;

				for (int i = 0; i < 4; i++) {
					int nx = direction[i][0] + x, ny = direction[i][1] + y;
					DFS(grid, nx, ny);
				}
				return flag;
			}

			int numIslands(vector<vector<char>>& grid) {
				int m = grid.size(), n = grid[0].size();
				int ans = 0;
				for (int i = 0;i < m; i++) {
					for (int j = 0; j < n; j++) {
						if (DFS(grid, i, j))
							ans++;
					}
				}
				return ans;
			}
	};
}

int main() {
	vector<vector<char>> grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'},
	};
	jike::Solution Test;
	cout << Test.jike::Solution::numIslands(grid) << endl;

	vector<vector<char>> grid2 = {
	{'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'},
	};

	jike::Solution Test2;
	cout << Test2.jike::Solution::numIslands(grid2) << endl;


}
