

/*
 * Date:2021-07-23 14:46
 * filename:32_从1到n整数中1出现的次数.cpp
 *
 */

/*
	 求出1-13的整数中1出现的次数,并算出100-1300的整数中1出现的次数？
	 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
	 ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

	 输入
	 13

	 返回值
	 6

	 1 10 11 12 13

*/

#include <bits/stdc++.h>
using namespace std;

int NumberOf1Between1AndN(unsigned int n) {
	int NumberOf1(unsigned int n);
	int number = 0;
	for (unsigned int i = 1; i <= n; ++i)
		number += NumberOf1(i);
	return number;
}

int NumberOf1(unsigned int n) {
	int number = 0;
	while(n) {
		if (n % 10 == 1) 
			number ++;
		n = n / 10;
	}
	return number;
}

int NumberOf1Between1AndN_2(int n) {
	int NumberOf1_2(const char* strN);
	if (n <= 0) return 0;
	char strN[50];
	sprintf(strN, "%d", n);

	return NumberOf1_2(strN);
}

int NumberOf1_2(const char* strN) {
	int PowerBase10(unsigned int n);
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0') return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0) return 0;
	if (length ==1 && first > 0) return 1;

	//假设strN是"21345"
	//numFirstDigit是数字10000 ～ 19999的第一个位中的数目
	int numFirstDigit = 0;
	if (first > 1) 
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;

	//numOtherDigits是1346 ~ 21345除了第一位之外的数位中的数目
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);

	//numRecursive是1 ～ 1345中的数目
	int numRecursive =   NumberOf1_2(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n) {
	int result = 1;
	for (unsigned int i = 0; i < n; ++i) 
		result *= 10;

	return result;
}

int main() {
	int ret = NumberOf1Between1AndN(12);
	cout << ret << endl;
	int NumberOf1_2(const char* strN);

	ret = NumberOf1_2("12");
	cout << ret << endl;
}
