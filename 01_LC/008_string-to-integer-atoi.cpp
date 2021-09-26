

/*
 * Date:2021-09-26 08:59
 * filename:008_string-to-integer-atoi.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
			if (s.length() == 0) return 0;

			int i = 0;
			int res = 0;
			int isNegative = 1;

			if (s[0] == '+') {
				i++;
			} 
			else if (s[0] == '-') {
				isNegative = -1;
				i++;
			}

			while(s[i] == ' ') {
				i++;
			}

			while (s[i] != '\0') {
				if (s[i] >= '0' && s[i] <= '9' && i < (int)s.length()) {
					res = res*10 + s[i] - '0';
				}
				if (res > INT_MAX) break;
				i++;
			}
		
			res *= isNegative;
			
			if (res < INT_MIN) res = INT_MIN;
			if (res > INT_MAX) res = INT_MAX;
			return res;
    }
    int mychar_Atoi(const char* str) {
			if (str == NULL) return 0;	
			const char* p = str;
			int res = 0;
			int isNegative = 1;
			while (*p++ == ' ') {

			}

			if (*p == '-') {
				isNegative = -1;
			}

			if (*p == '-' || *p == '+') {
				p++;
			}

			while (*p != '\0') {
				if (*p >= '0' && *p < '9') {
					res = res*10 + *p - '0';
				}
				p++;
			}
			return res *= isNegative;
		}
};

int main() {
	Solution fun;

	cout << "-1231415:--->" << fun.myAtoi("-1231415") << endl;
	cout << "+12315:--->" << fun.myAtoi("+12315") << endl;

	cout << "   123:--->" << fun.myAtoi("    123") << endl; 

	cout << "+1234:--->" << fun.mychar_Atoi("+1234") << endl;

	cout << "-1234:--->" << fun.mychar_Atoi("-1234") << endl;

	cout << "askdh   12314:--->" << fun.mychar_Atoi("askdh    12314") << endl;
}
