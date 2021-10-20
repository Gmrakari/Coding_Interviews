

/*
 * Date:2021-10-20 21:07
 * filename:04_二进制加法.cpp
 *
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int add(int a, int b) {
	int ret = a;
	while (b) {
		int temp = a;
		a = a ^ b;
		b = (temp & b) << 1;
		ret = a;
	}
	return ret;
}

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

int vec_to_int_2(vector<int> &vec) {
	int ret = 0;
	int b = 1;
	for (int i = vec.size();i >= 0;i--) {
		ret += b * vec[i];
		b *= 10;
	}
	return ret;
}

int vec_to_int(vector<int> &vec) {
	auto first = vec.rbegin();
	auto end = vec.rbegin();
	int ret = 0;
	while (first != end) {
		ret = *first;  
		ret = ret * 10 + ret;
		first++;
	}
	return ret;
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
	int num;
	int m;
	scanf("%d", &num);
	scanf("%d", &m);
	
	vector<int> res_num = transfer(num, m);
	output(res_num);
	int ret = vec_to_int_2(res_num);
	cout << "ret:" << ret << endl;
}
