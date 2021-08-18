

/*
 * Date:2021-08-18 16:36
 * filename:01_提取优惠券码.cpp
 *
 */

/*
 * 【题目描述】

携程客户下单的时候系统会发放一个优惠券码，用户在前端界面看到的展现形式如下：
“1Ct3r4ip_ti4C6k9Et^”，包含数字、字母、和 [\]^_’ 6 个特殊字符。
为了安全性，系统在使用的时候做解密操作，删除里面的数字部分，只验字母 A~z 以及[\]^_’ 6 个特殊
字符部分才是有效的，并且在解密后不会重新排序字母的顺序，按照之前的对应顺序排列。
如上所示，如果一个客户拿到的优惠券码是这个：1Ct3r4ip_ti4C6k9Et^ ，
请用 任何一种语言实现提取正确的优惠券码。

输入描述: :
1Ct3r4ip_ti4C6k9Et^

输出描述: :
Ctrip_tiCkEt^

输入样例：
1Ct3r4ip_ti4C6k9Et^

输出样例：
Ctrip_tiCkEt^

*/

#include <bits/stdc++.h>
using namespace std;

void get_str(string& str) {
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9' ) {
			continue;
		}
		else {
			cout << str[i];
		}
	}
	cout << endl;
}

int main() {
	string str = "1Ct3r4ip_ti4C6k9Et^";
	get_str(str);
}
