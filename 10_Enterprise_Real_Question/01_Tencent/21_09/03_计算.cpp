

/*
 * Date:2021-09-26 20:56
 * filename:03_计算.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;


long long calc(string str) {
	if (str.length() == 0) return 0;

	int i = 0;
	long long res = 0;
	while (i < (int)str.length() && str[i] >= '0' && str[i] <= '9' && (str[i] == '@' || str[i] == '+' || str[i] == 'x' )) {
		if (str[i] >= '0' && str[i] <= '9') {
			res = res*10 + str[i] - '0';
			i++;
		}
		else if (str[i] == '+') {

		}
						
	}
	return 0;
}

long long calc(const char* p) {
	stack<int> s_num;
	stack<char> s_sig;
	
	int i = 0;
	while (*p++ != '\0') {
		if (*p >= '0' && *p <= '9') {
			s_num.push(*p);
			p++;
		}
		else if (*p == '@' || *p == '+') {
			s_sig.push(*p);
			p++;
		}

		if ()
	}

}
