

/*
 * Date:2021-05-30 20:21
 * filename:231-power_of_two.cpp
 *
 * 如果是以2为幂次方的数，那么((x & (x - 1)) == 0)
 *
 */

/*
 * cout << ( 8 & 7 ) << endl; //0
 * cout << ( 7 & 6 ) << endl; //6
 *
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0 || n < 1) return false;
        uint32_t x = n;
        if( (x & (x - 1)) == 0 && x != 0) {
            return true;
        }
        return false;
    }
};
