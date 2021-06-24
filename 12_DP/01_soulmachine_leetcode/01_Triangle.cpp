

/*
 * Date:2021-06-24 22:20
 * filename:01_Triangle.cpp
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//设状态为f(i,j),表示从位置(i, j)出发，路径的最小和
//则状态转移方程为:
//f(i, j) = min{f(i + 1,j), f(i + 1,j + 1)} + (i, j);

class Solution {
public:
	int minimumTotal (vector<vector<int>>& triangle) {
		for (int i = triangle.size() - 2;i >= 0;--i) {
			for (int j = 0;j < i + 1;++j) {
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};

int main() {
	vector<vector<int>> vec = {
														{2},
														{3,4},
														{6,5,7},
														{4,1,8,3}
														};
	Solution so;
	cout << so.minimumTotal(vec) << endl;
}
