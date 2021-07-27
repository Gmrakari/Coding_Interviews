

/*
 * Date:2021-07-27 09:49
 * filename:42_翻转单词顺序和左旋转字符串.cpp
 *
 */

/*
 * #题意
题目描述

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

样例输入

student. a am I

I'm a Freshman and I like JOBDU!

样例输出

I am a student.

JOBDU! like I and Freshman a I'm

第一步翻转句子中的所有的字符

比如翻转 I am a student. == > .tneduts a ma I  此时不但翻转了句子中的单词的顺序，连单词内的字符顺序也被翻转了

第二步再翻转每个单词中字符的顺序，就得到了"student. a am I"

关键在于实现一个函数以翻转字符串中的一段

*/

#include <bits/stdc++.h>
using namespace std;

void Reverse(char *pBegin, char *pEnd) {
	if (pBegin == NULL || pEnd == NULL) 
		return ;

	while (pBegin < pEnd) {
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;

		pBegin++, pEnd--;
	}
}

//先翻转整个句子，再翻转句子中的每个单词

char *ReverseSetence(char *pData) {
	if (pData == NULL)
		return NULL;

	char *pBegin = pData;
	char *pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	//翻转整个句子
	Reverse(pBegin, pEnd);

	//翻转句子中的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0') {
		if (*pBegin == ' ') {
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0') {
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else {
			pEnd++;
		}
	}
	return pData;
}

//通过扫描空格来确定每个单词的起始和终止位置


//左旋
//
//以"abcdefg"为例，我们可以把它分为两个部分
//把它的前两个字符移到后面，我们就把前两个字符分到第一部分，把后面的所有字符都分到第二部分
//"cdefgab"
//"ab","cdefg"
//我们先分别翻转这两部分,于是得到"bagfedc",接下来再翻转整个字符串,得到"cdefgab"
char* LeftRotateString(char* pStr, int n) {
	if (pStr != NULL) {
		int nLength = static_cast<int>(strlen(pStr));

		if (nLength > 0 && n > 0 && n < nLength) {
			char *pFirstStart = pStr;
			char *pFirstEnd = pStr + n - 1;
			char *pSecondStart = pStr + n;
			char *pSecondEnd = pStr + nLength - 1;

			//翻转字符串的前面n个字符
			Reverse(pFirstStart, pFirstEnd);
			//翻转字符串后面的部分
			Reverse(pSecondStart, pSecondEnd);
			//翻转整个字符串
			Reverse(pFirstStart, pSecondEnd);
		}
	}
	return pStr;
}

void Test_1() {
	char input[] = "I am a student.";
	char *ReverseSetence(char *pData);

  char *expected;
	cout << "original:" << input << endl;
	expected = ReverseSetence(input);

	cout << "reverse:";
	for (int i = 0;expected[i] != '\0';expected++) {
		cout << expected[i];
	}
	cout << endl;
}

void Test_2() {
	char* LeftRotateString(char* pStr, int n);
	char input[] = "abcdefg";
	int n = 2;

	char *expected;
	cout << "original:" << input << endl;
	expected = LeftRotateString(input, n);

	cout << "reverse, n = 2:";
	for (int i = 0; expected[i] != '\0';expected++) {
		cout << expected[i];
	}
	cout << endl;
}

int main() {
	Test_1();
	Test_2();
}
