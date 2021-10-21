

/*
 * Date:2021-10-21 18:39
 * filename:08_反转字符串.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

string reverse_str(string &str) {
	reverse(str.begin(), str.end());
	return str;
}

char* reverse(char *str) {
	if (str == NULL) {
		return NULL;
	}
	int length = 0;
	length = strlen(str);
	for (int i = 0, j = length - 1;i < j;i++,j--) {
		int c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	return str;
}

int main () {
	char s[] = "hello world";
	string str = "hello world";
	reverse(s);
	cout << "charre:";
	cout << s << endl;

	cout << "string:" << reverse_str(str) << endl;
}
