

/*
 * Date:2021-06-05 15:08
 * filename:152_maximun-product-subarray.cpp
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp[nums.size()][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int res = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int x = i % 2;
            int y = (i - 1) % 2;
            dp[x][0] = max(max(dp[y][0] * nums[i], dp[y][1] * nums[i]),nums[i]);
            dp[x][1] = min(min(dp[y][0] * nums[i], dp[y][1] * nums[i]),nums[i]);
            res = max(res, dp[x][0]);
        }
        return res;

    }
};

class Solution_2 {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> maxF(nums), minF(nums);
		for (int i = 1; i <(int)nums.size(); ++i) {
			maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
			minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
		}
		return *max_element(maxF.begin(), maxF.end());
	}
};

int main() {
	Solution su;
	vector<int> vec = {-2,1,3,4};
	cout << "Solution_1:";
	cout <<su.maxProduct(vec) << endl;

	cout << "Solution_2:";
	Solution_2 so;
	cout << so.maxProduct(vec) << endl;
	return 0;
}
