/*
*
** @filename:912Sort an Array
** @date:2022-05-25 09:01:57
*  @author:gmrakari
*
*/

#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> ret = nums;
        quicksort(ret, 0, ret.size());
        return ret;
    }

    int partition(vector<int>& nums, int low, int high) {
        int pv = nums[low];
        while (low < high) {
            while (low < high && pv < nums[high]) {
                high--;
            }
            swap(nums[low], nums[high]);
            while (low <= high && pv > nums[low]) {
                low++;
            }
            swap(nums[low], nums[high]);
        }
        return low;
    }

    void quicksort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pv = partition(nums, low, high);
            quicksort(nums, low, pv - 1);
            quicksort(nums, pv + 1, high);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


void test() {
    cout << "Begin" << endl;
    
    Solution s;
    vector<int> vec{7, 1, 5, 3, 6, 4};
    vector<int> ret = s.sortArray(vec);

    for (auto i : ret) {
        cout << i << " ";
    }

    cout << "\nEnd" << endl;
}


int main()
{
    test();
}