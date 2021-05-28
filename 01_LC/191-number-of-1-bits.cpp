

/*
 * Date:2021-05-28 11:13
 * filename:191-number-of-1-bits.cpp
 *
 */

/*
 * 除去最后一位1
 * n = n & (n - 1);
 *
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            if(n & 1 == 1) {
                ++cnt;
                n = n >> 1;
            }
        }
        return cnt;
    }
};
