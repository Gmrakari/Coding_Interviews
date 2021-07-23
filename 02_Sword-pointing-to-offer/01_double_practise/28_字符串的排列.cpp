

/*
 * Date:2021-07-23 11:41
 * filename:028_字符串的排列.cpp
 *
 */

/*

#题意
题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列

例如输入字符串abc,

则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

结果请按字母顺序输出。

注意 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母

*/

#include <iostream>
#include <string>
#include <cstdio>

/*
 * 首先求所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换
 * 第二步固定第一个字符，求后面所有字符的排列
 *
 * 这个时候我们仍把后面的所有字符分成两部分:后面字符的地一个字符，以及这个字符之后的所有字符
 *
 * 然后把地一个字符逐一和它后面的字符交换
 *
 */

void Permutation(char* pStr) {
	void Permutation(char *pStr, char *pBegin);
	if (pStr == NULL) return ;
	Permutation(pStr, pStr);
}

//pStr指向整个字符串的第一个字符,pBegin指向当前我们做排列操作的字符串的第一个字符
//在每一次递归的时候，我们从pBegin向后扫描每个字符(即指针pCh指向的字符)
//在交换pBegin和pCh指向的字符之后，我们再对pBegin后面的字符串递归做排列操作,直至pBegin只想字符串的末尾
void Permutation(char *pStr, char *pBegin) {
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	}
	else {
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

int main() {
	char str[] = "abc";
	Permutation(str);
}
