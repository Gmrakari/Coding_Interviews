

/*
 * Date:2021-08-17 17:46
 * filename:53_正则表达是匹配.cpp
 *
 */


/*
#题意
题目描述

请实现一个函数用来匹配包括'.'和''的正则表达式。模式中的字符'.'表示任意一个字符，而''表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"abaca"匹配，但是与"aa.a"和"ab*a"均不匹配

样例输入

"a","ab*a"

样例输出

false

*/

#include <iostream>
using namespace std;

bool match(char* str, char* pattern) {
	bool matchCore(char* str, char* pattern);
	if (str == NULL || pattern == NULL)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern) {
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str == '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*') {
		if (*pattern == *str || (*pattern == '.' && *str != '\0')) 
			//move on the next state
			return matchCore(str + 1, pattern + 2)
				//stay on the current state
				|| matchCore(str + 1, pattern)
				// ignore a '*'
				|| matchCore(str, pattern + 2);
		else 
			// ignore a '*'
			return matchCore(str, pattern + 2);
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;

}

int main() {
	bool match(char* str, char* pattern);
	bool ret;
	char str[] = "aaa";
	//char pattern[] = "ab*ac*c";
	//char pattern[] = "a.a";
	char pattern[] = "aa*";
	ret = match(str, pattern);
	cout << ret << endl;

}
