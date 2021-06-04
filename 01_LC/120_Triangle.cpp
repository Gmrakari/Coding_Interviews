

/*
 * Date:2021-06-04 10:52
 * filename:120_Triangle.cpp
 *
 */

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
