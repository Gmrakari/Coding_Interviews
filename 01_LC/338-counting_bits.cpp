

/*
 * Date:2021-05-30 20:34
 * filename:338-counting_bits.cpp
 *
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            bits[i] += bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};
