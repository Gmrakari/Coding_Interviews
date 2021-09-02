

/*
 * Date:2021-09-02 19:07
 * filename:55_字符流中第一个不重复的字符.cpp
 *
 */

/*
 * #题目描述

请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符"google"时，第一个只出现一次的字符是"l"。
如果当前字符流没有存在出现一次的字符，返回#字符。

*/

/*
 * 思路:
 * 字符只能一个接着一个从字符流中读出来。
 * 可以定义个数据容器来保存字符在字符流中的位置。当一个字符第一次从字符流中读出来时，
 * 把它在字符流中的位置保存到数据容器里。当这个字符再次从字符流中被读出来时，
 * 那么它就不是只出现一次的字符，也就可以被忽略了。
 * 这时把它在数据容器里保存的值更新成一个特殊的值
 *
 */

#include <iostream>
#include <limits>
using namespace std;

class CharStatistics {
public:
	CharStatistics() :index(0) {
		for (int i = 0; i < 256; ++i) 
			occurrence[i] = -1;
	}

	void Insert(char ch) {
		if (occurrence[ch] == -1) 
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;
		index++;
	}

	char FirstAppearingOnce() {
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; ++i) {
			if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}
		return ch;
	}
private:
	int occurrence[256];
	int index;
};
