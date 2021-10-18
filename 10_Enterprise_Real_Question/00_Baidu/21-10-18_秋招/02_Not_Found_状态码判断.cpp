

/*
 * Date:2021-10-18 19:49
 * filename:02_Not_Found_状态码判断.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

string Find(string str) {
	if (str.length() == 0)
		return NULL;
	char temp = str[0];
	//char res[10];
	string res;
	if (temp == '4' || temp == '5') {
		res = "Yes";
	}
	else {
		res = "No";
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	string s;
	vector<string> res;
	for (int i = 0; i < n;i++) {
		cin >> s;
		res.push_back(Find(s));
	}

	for (auto j : res) {
		cout << j << endl;
	}
	return 0;
}
