/*
*
** @filename:3Longest Substring Without Repeating Characters
** @date:2022-05-16 11:25:46
*  @author:gmrakari
*
*/

#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        unordered_set<char> occ;
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


void test() {
    cout << "Begin" << endl;
    
    Solution s;
    string str = "abcabcbb";
    int ret = s.lengthOfLongestSubstring(str);
    cout << ret << endl;
    cout << "End" << endl;
}


int main()
{
    test();
}