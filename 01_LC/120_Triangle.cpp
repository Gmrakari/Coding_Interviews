

/*
 * Date:2021-06-04 10:52
 * filename:120_Triangle.cpp
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
			vector<int> mini = triangle[triangle.size() - 1];
			for ( int i = triangle.size() - 2; i >= 0; --i ) {
				for (int j = 0; j < triangle[i].size(); ++j) {
					mini[j] = min(mini[j],mini[j + 1]) + triangle[i][j];
				}
			}
			return mini[0];
    }
};

class Solution_2{
public :
	int miniumTotal (vector<vector<int>>& triangle) {
		for (int i = triangle.size() - 2;i >= 0;i--) {
			for (int j = 0; j < i + 1;++j) {
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

	Solution_2 so;
	cout << so.miniumTotal(vec) << endl;
}
