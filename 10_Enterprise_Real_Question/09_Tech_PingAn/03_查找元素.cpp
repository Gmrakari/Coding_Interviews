

/*
 * Date:2021-08-14 17:24
 * filename:03_查找元素.cpp
 *
 */

/*
 *

【题目描述】
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
输入描述：
一个数组

输出描述：
返回多个满足条件的元素组合

输入样例：
[-1,0,1,2,-1,-4]

输出样例：
-1 -1 2
-1 0 1

*/

/*
 * 枚举a和b,在排序后的数组里二分查找c = -a-b.注意在找c的时候不能与a和b重复
 */


#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
const int inf = 0x3f3f3f3f;
int n;
int a[N];
set<pair<int, int>> vis;

multiset<int> s;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}

	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n; ++i) {
		s.erase(s.find(a[i]));
		for (int j = i + 1; j <= n; ++j) {
			s.erase(s.find(a[j]));
			if(s.count(-a[i]-a[j])) {
				int b[3] = {a[i], a[j], -a[i]-a[j]};
				sort(b, b + 3);
				auto p = make_pair(b[0], b[1]);
				if (!vis.count(p)) {
					printf("%d %d %d\n", a[i], a[j], -a[i]-a[j]);
					vis.insert(p);
				}
			}
			s.insert(a[j]);
		}
		s.insert(a[i]);
	}
	return 0;
}


