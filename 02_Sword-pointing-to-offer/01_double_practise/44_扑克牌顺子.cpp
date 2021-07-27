

/*
 * Date:2021-07-27 10:59
 * filename:44_扑克牌顺子.cpp
 *
 */

/*
 * LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...

 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票 ,嘿嘿！！
 “红心A,黑桃3,小王,大王,方片5”, “Oh My God!”不是顺子.....
 LL不高兴了,他想了想,决定大\小王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。 
 上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。

 LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。

 样例输入

 3 5 1 0 4

 3 5 4 7 6

 3 5 7 4 8

 样例输出

 So Lucky!

 So Lucky!

 Oh My God!

*/

/*
 * 首先把数组排序，再统计数组中0的个数，最后统计排序之后的数组相邻数字之间的空缺总数
 *  如果空缺的总数小于或者等于0的个数，那么这个数组就是连续的，反之则不连续
 *
 *  如果数组中的非0数字重复出现，则该数组不是连续的。
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool IsContinuous(int* numbers, int length) {
	int compare(const void *arg1, const void *arg2);
	if (numbers == NULL || length < 1) 
		return false;

	qsort(numbers, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	//统计数组中0的个数
	for (int i = 0; i < length && numbers[i] == 0; ++i)
		++numberOfZero;

	//统计数组中的间隔数目
	int small = numberOfZero;
	int big = small + 1;

	while (big < length) {
		//两个相等，有对子，不可能是顺子
		if (numbers[small] == numbers[big])
			return false;

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}

int compare(const void *arg1, const void *arg2) {
	return *(int*)arg1 - *(int*)arg2;
}

int main() {
	bool IsContinuous(int* numbers, int length);
	int number[] = {3, 5, 1, 0, 4};
	int number2[] = {3, 5, 4, 7, 6};
	int number3[] = {3, 5, 7, 4, 8};
	int length = sizeof(number) / sizeof(number[0]);
	int length2 = sizeof(number2) / sizeof(number2[0]);
	int length3 = sizeof(number3) / sizeof(number3[0]);
	bool result = IsContinuous(number, length);
	cout << result << endl;

	result = IsContinuous(number2, length2);
	cout << result << endl;
	result = IsContinuous(number3, length3);
	cout << result << endl;

}


// 3 5 1 0 4

//3 5 4 7 6

//3 5 7 4 8
