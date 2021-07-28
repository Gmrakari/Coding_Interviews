

/*
 * Date:2021-07-28 16:03
 * filename:49_把字符串转换成整数.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

enum Status {
	kValid = 0, kInvalid
};

int g_nStatus = kValid;

int StrToInt(const char* str) {
	long long StrToIntCore(const char* digit, bool minus);
	g_nStatus = kInvalid;
	long long num = 0;

	if (str != NULL && *str != '\0') {
		bool minus = false;
		
		//处理空格
		while (*str == ' ') {
			str++;
		}

		if (*str == '+') 
			str++;
		else if (*str == '-') {
			str++;
			minus = true;
		}

		if (*str != '\0') {
			num = StrToIntCore(str, minus);
		}
	}
	return (int)num;
}

long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;
	while (*digit != '\0') {
		if (*digit >= '0' && *digit <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF)
					|| (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			digit++;
		}
		else {
			num = 0;
			break;
		}
	}
	if (*digit == '\0') {
		g_nStatus = kValid;
	}
	return num;
}

void test() {
	int StrToInt(const char* str);
	int ret = StrToInt("-100");
	cout << ret << endl;

	ret = StrToInt("12345");
	cout << ret << endl;

	ret = StrToInt("  +21");
	cout << ret << endl;
}

int main() {
	test();
}
