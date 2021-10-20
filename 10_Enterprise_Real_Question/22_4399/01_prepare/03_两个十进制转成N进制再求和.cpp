

/*
 * Date:2021-10-20 20:44
 * filename:03_两个十进制转成N进制再求和.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> transfer(int num, int n) {
	vector<int> res;
	int temp = 0;
	while (num > 0) {
		temp = num % n;
		res.push_back(temp);
		num = num / n;
	}
	return res;
}

void output(vector<int> &res) {
	auto first = res.rbegin();
	auto end = res.rend();
	while (first != end) {
		cout << *first;
		first++;
	}
	cout << endl;
}

int main() {
	int num1, num2;
	int m;

	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &m);
	vector<int> res_num1 = transfer(num1, m);
	vector<int> res_num2 = transfer(num1, m);
	output(res_num1);
	output(res_num2);

	int ret = num1 + num2;
	vector<int> m_ret = transfer(ret, m);
	output(m_ret);

	return 0;
}
