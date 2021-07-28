

/*
 * Date:2021-07-28 12:24
 * filename:04_atoi.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int m_atoi(char* pstr) {
	if (pstr == NULL) {
		return 0;
	}
	int Ret_Integer = 0;
	int Integer_sign = 1;

	//跳过前面的空格
	while (isspace(*pstr) == 0) {
		pstr++;
	}

	/*
	 * 判断正负号
	 * 如果是正号，指针指向下一个字符
	 * 如果是负号，把符号标记为Integer_sign置-1,然后再把指针指向下一个字符
	 *
	 */

	if (*pstr == '-') {
		Integer_sign = -1;
	}

	if (*pstr == '-' || *pstr == '+') {
		pstr++;
	}

	/*
	 * 把数字字符串逐个转换成整数
	 * 并把最后转换好的整数赋值给Ret_Integer
	 */
	while (*pstr >= '0' && *pstr <= '9') {
		Ret_Integer = Ret_Integer * 10 + *pstr - '0';
		pstr++;
	}
	Ret_Integer = Integer_sign * Ret_Integer;

	return Ret_Integer;
}

void test() {
	char a[] = "-100";
	char b[] = "213";
	int c = 0;

	int m_atoi(char *);
	c = m_atoi(a) + m_atoi(b);

	printf("%d",m_atoi(a));
	cout << "m_atoi(a) : " << m_atoi(a) << endl;
	cout << "m_atoi(b) : " << m_atoi(b) << endl;

	cout << c << endl;
}

int main() {
	test();
}
