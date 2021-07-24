

/*
 * Date:2021-07-24 15:32
 * filename:40_数组中只出现一次的数字.cpp
 *
 */


/*
#题意
题目描述

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字

样例输入

2 4 3 6 3 2 5 5

样例输出

4 6

*/


#include <bits/stdc++.h>
using namespace std;

/*
 * 任何一个数字异或它自己都等于0
 * 如果我们从头到尾依次异或数组中的每一个数字，
 * 那么最终的结果刚好是那个只出现一次的数字,
 * 因为那些成对出现的两次的数字全部在异或中抵消了
 */


void FindNumsApperOnce(vector<int> data, int *num1, int *num2) {
	unordered_map<int, int> unmp;
	for (int i = 0; i < (int)data.size(); ++i) {
		unmp[data[i]] += 1;
	}

	auto it = unmp.begin();
	while (it != unmp.end()) {
		it (it->second == 1) {
			*num1 = it->first;
			++it1;
			break;
		}
		++it;
	}

	while (it != unmp.end()) {
		it (it->second == 1) {
			*num2 = it->firstl
				break;
		}
		++it;
	}
}

