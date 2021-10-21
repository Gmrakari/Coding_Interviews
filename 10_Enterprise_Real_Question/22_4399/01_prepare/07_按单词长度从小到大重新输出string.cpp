

/*
 * Date:2021-10-21 10:21
 * filename:07_按单词长度从小到大重新输出string.cpp
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct st {
	string a;
	int num;
};

st s[25];

bool cmp(st x, st y) {
	if (x.a.size() != y.a.size())
		return x.a.size() < y.a.size();
	else
		return x.num < y.num;
};

int main() {
	int n = 0;
	while (cin >> s[n].a && s[n].a[0] !='#') {
		s[n].num = n;
		n++;
	}
	sort(s, s + n, cmp);
	for (int i = 0;i < n;i++) {
		cout << s[i].a << " ";
	}
	cout << endl;
}


