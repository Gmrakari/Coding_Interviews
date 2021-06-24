

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

/*
 * NC32 求平方根
 * https://www.nowcoder.com/practice/09fbfb16140b40499951f55113f2166c
 * Date:2021-06-24 19:50
 *
 */

class Solution_2 {
public:
    /**
     *
     * @param x int整型
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if (x == 0 || x == 1) return x;
        long low = 0;
        long high = x;
        long mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid * mid == x) return (int) mid;
            else if (mid * mid < x) low = (int)(mid + 1);
            else high = (int)(mid - 1);
        }
       return high;
    }
};
