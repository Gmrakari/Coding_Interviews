
/*
 * Date:2021-09-24 20:02
 * filename:03_lc_008_atoi.cpp
 */

#include <bist/stdc++.h>
using namespace std;

class Solution {
public:
  int my_atois(string s) {
    int i = 0;
    if (i == s.size()) return 0;
    long long res = 0;
    int isNegative = 1;
    
    /*
     * 先判断是否含有空格 再符号再进行逐个判断
     */
    
    while (s[i] == ' ' && i < s.size()) {
      i++;  
    }
    
    if (s[i] == '+') {
      i++;
    } 
    else if (s[i] == '-') {
      isNegative = -1;
      i++;
    }
    
    while (s[i] >= '0' && s[i] <= '9' && i < s.size()) {
      res = res * 10 + s[i] - '0';
      i++;
      if (res > INT_MAX) break;
    }
    res *= isNegative;
    if (res > INT_MAX) res = INT_MAX;
    
    if (res < INT_MIN) res = INT_MIN;
    
    return res;
  }
};

int main() {
  Solution test;
  cout << test.my_atois("-12031231294") << endl;
  cout << endl;
}
