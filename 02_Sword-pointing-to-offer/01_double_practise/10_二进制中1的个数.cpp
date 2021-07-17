

/*
 * Date:2021-07-17 11:37
 * filename:10_二进制中1的个数.cpp
 *
 */

/*
题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

样例输入

3 4 5 -1

样例输出

1 2 3 2

如何判断一个整数的最右边的二进制数是不是1

只要把整数和1做位运算看结果是不是0就知道。

如果一个整数与1做与运算的结果是1 表示该整数最右边一位是1，否则为0

*/

int NUmberOf1(int n) {
	int count = 0;
	while (n) {
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

int NUmberOf2(int n) {
	int count = 0;
	unsigned int flag = 1;
	while(flag) {
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf3(int n) {
	int count = 0;
	while (n) {
		++count;
		n = (n - 1) & n;
	}
	return count;
}
