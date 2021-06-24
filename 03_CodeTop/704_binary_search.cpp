

/*
 * Date:2021-06-24 15:01
 * filename:704_binary_search.cpp
 *
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return -1;
    }
};
