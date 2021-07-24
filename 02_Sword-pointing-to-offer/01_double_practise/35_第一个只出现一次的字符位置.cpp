

/*
 * Date:2021-07-24 11:18
 * filename:35_第一个只出现一次的字符位置.cpp
 *
 */

/*
#题意
题目描述

在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。
若为空串，返回-1。位置索引从0开始


如输入"abaccdeff" 则输入'b'

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 我们可以定义哈系表的键值(key)是字符，而值(Value)是该字符出现的次数
 * 同时我们还需要从头开始扫描字符串两次
 * 第一次扫描字符串时，每扫描到一个字符就在哈系表的对应项中把次数加1
 * 接下来第二次扫描时，每扫描到一个字符就能从哈系表中得到该字符出现的次数
 *
 */

char FirstNotRepeatingChar(char* pString) {
	if (pString == NULL)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for(unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;

	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)] ++;

	pHashKey = pString;
	while (*pHashKey != '\0') {
		if (hashTable[*pHashKey] == 1) 
			return *pHashKey;

		pHashKey++;
	}
	return '\0';
}


int main() {
	char tmp = FirstNotRepeatingChar("abaccdeff");
	cout << tmp << endl;
}
