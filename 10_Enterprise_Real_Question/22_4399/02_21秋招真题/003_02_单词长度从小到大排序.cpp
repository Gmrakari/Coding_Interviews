

/*
 * Date:2021-10-22 08:23
 * filename:02_单词长度从小到大排序.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct m_str {
	string a;
	int num;
};

m_str s[25];

bool cmp(m_str x, m_str y) {
	if (x.a.size() != y.a.size()) {
		return x.a.size() < y.a.size();
	}
	else {
		return x.num < y.num;
	}
}

string Arrange(string s) {
	vector<string> res;
	res.push_back(s);
	sort(res.begin(),res.end());
	for (int i = 0;i < (int)res.size();i++) {
		cout << res[i] << ' ';
	}
	return s;
}

int main() {
	string str;
	vector<string> res;
	cin >> str;
	
	Arrange(str);

	return 0;
}
