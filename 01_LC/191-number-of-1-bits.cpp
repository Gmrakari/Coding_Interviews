

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

/*
 *
 * 21春招 37互娱研发笔试算法题 第二题
 * 没有做出来 其实剑指offer里面就有 但是没有印象 现在有了
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

/*
 * 除2 取余数
 * 
 */

class Solution_2 {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            ret = ret + n % 2;
            n = n >> 1;
        }
        return ret;
    }
};
