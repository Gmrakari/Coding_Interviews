

/*
 * Date:2021-12-18 23:19
 * filename:3-1-2_can_run.cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int calculateExtraNum(int totalNum, int exchangeNum) {
			int ret = 0; //保存的结果
			int left = 0; //余数
			int temp = 0;
			int total_left = 0; //总的余数
			while (totalNum > 0)  {
				temp = totalNum / exchangeNum; //需要准备的瓶子
				left = totalNum % exchangeNum; // 剩余的瓶子

				if (left != 0) { //有剩余的瓶子
					//先考虑left总共满足能换多少个瓶子 如果达到exchangeNum个
					//把当前总的剩余瓶子数 清零
					if (left % exchangeNum == 0) {
						total_left = 0;
					}
					//剩余的瓶子不能换（到不到exchangNum个)
					else {
						total_left += left;
						ret += temp;
					}

					// 如果total_left能满足exchangeNum个，那么能兑换的数字+1
					//或者 total_left 超过 exchangeNum 个，那么能兑换的数字+1
					if (total_left % exchangeNum == 0 || total_left / exchangeNum == 1) {
						ret += 1;
						//判断当前总的剩余瓶子是否超过exchangeNum
						//超过exchangeNum，就把total_left减掉 恢复总的剩余瓶子数
						if (total_left == exchangeNum) {
							total_left -= exchangeNum;
						}
					}
				}
				//没有剩余的瓶子
				else {
					ret += temp;
				}
				//更新现有的瓶子
				totalNum = temp;
			}
			return ret;
		}
};

void test() {
	Solution s;
	//cout << s.calculateExtraNum(20, 4) << endl;
	//cout << s.calculateExtraNum(4, 4) << endl;
	//cout << s.calculateExtraNum(30, 3) << endl;
	//cout << s.calculateExtraNum(31, 3) << endl;
	//cout << s.calculateExtraNum(15, 4) << endl;
	cout << 86 + s.calculateExtraNum(86, 3) << endl;
	//cout << s.calculateExtraNum(86, 3) << endl;
}

int main() {
	test();

}
