

/*
 * Date:2021-07-27 11:29
 * filename:45_圆圈中最后剩下的数.cpp
 *
 */

/*
 * #题意
题目描述

每年六一儿童节,NowCoder都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。

HF作为NowCoder的资深元老,自然也准备了一些小游戏。

其中,有个游戏是这样的:

首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。

每次喊到m的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,

并且拿到NowCoder名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。

请你试着想下,哪个小朋友会得到这份礼品呢？

样例输入
1 10

8 5

6 6

样例输出
1

3

4

*/

#include <bits/stdc++.h>
using namespace std;

/*
 * 用环形链表模拟圆圈
 */

int LastRemaining(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1) 
		return -1;

	unsigned int i = 0;
	list<int> numbers;

	for (i = 0; i < n; ++i) 
		numbers.push_back(i);
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1) {
		for (unsigned int i = 1; i < m;++i) {
			current++;
			if (current == numbers.end()) 
				current = numbers.begin();
		}

		list<int>::iterator next = ++ current;
		if (next == numbers.end()) 
			next = numbers.begin();

		--current;
		numbers.erase(current);
		current = next;
	}
	return (*current);
}

int LastRemaining_2(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1) 
		return -1;

	int last = 0;
	for (unsigned int i = 2; i <= n;i++) 
		last = (last + m) % i;

	return last;
}

int main() {
	int LastRemaining(unsigned int n, unsigned int m);
	int ret = LastRemaining(1, 10);
	cout << ret << endl;

	ret = LastRemaining(8, 5);
	cout << ret << endl;

	ret = LastRemaining(6, 6);
	cout << ret << endl;

	cout << "sulution2:" << endl;

	ret = LastRemaining_2(1, 10);
	cout << ret << endl;
	ret = LastRemaining_2(8, 5);
	cout << ret << endl;
	ret = LastRemaining_2(6, 6);
	cout << ret << endl;
}
