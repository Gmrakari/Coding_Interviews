

/*
 * Date:2021-10-20 16:12
 * filename:002_03_代码.cpp
 *
 */

#include <iostream>
#include <string>

using namespace std;

int cal(char *s) {
	if (*s == 0)
		return 0;
	return cal(s + 1) + 1;
}

char h(char *s, int n,int i, int &p) {
	if (i >= n)
		return 0;

	char c = h(s, n, 2 * i + 1, p);
	if (p == 0)
		return c;

	--p;
	if (p == 0)
		return s[i];

	return h(s, n, 2 * i + 2, p);
}

int main(int argc, char* argv[]) {
	char s[] = "abcdefghjik";
	int p = 9;
	cout << h(s, cal(s), 0, p);
	return 0;
}
