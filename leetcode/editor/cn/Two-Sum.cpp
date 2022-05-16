/*
*
** @filename:1Two Sum
** @date:2022-05-16 10:24:09
*  @author:gmrakari
*
*/

#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 0) return {};
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


void test() {
    cout << "Begin" << endl;
    
    Solution s;
    vector<int> vec{7, 1, 5, 3, 6, 4};
    int target = 6;

    vector<int> ret = s.twoSum(vec, target);

    for (auto i : ret) {
        cout << i << " ";
    }
    cout <<endl;
    
    cout << "End" << endl;
}


int main()
{
    test();
}