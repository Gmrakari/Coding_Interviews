

/*
 * Date:2021-07-21 14:18
 * filename:01_特征提取-研发.cpp
 *
 */

/*
 *
 小明是一名算法工程师，同时也是一名铲屎官。
 某天，他突发奇想，想从猫咪的视频里挖掘一些猫咪的运动信息。
 为了提取运动信息，他需要从视频的每一帧提取“猫咪特征”。
 一个猫咪特征是一个两维的vector<x,y>。如果 x_1=x_2 and y_1=y_2，那么这俩是同一个特征。
 因此，如果喵咪特征连续一致，可以认为喵咪在运动。
 也就是说，如果特征<a,b>在持续帧里出现，那么它将构成特征运动。
 比如，特征<a,b>在第 2/3/4/7/8 帧出现，那么该特征将形成两个特征运动 2-3-4 和 7-8。
 现在，给定每一帧的特征，特征的数量可能不一样。小明期望能找到最长的特征运动。
 输入描述:

 1、第一行包含一个正整数 N，代表测试用例的个数。
 2、每个测试用例的第一行包含一个正整数 M，代表视频的帧数。
 3、接下来的 M 行，每行代表一帧。其中，第一个数字是该帧的特征个数，接下来的数字是在特征的取值；
 比如样例输入第三行里，2 代表该帧有两个猫咪特征，<1，1>和<2，2>
 所有用例的输入特征总数和<1000004、N 满足 1≤N≤100000，M 满足 1≤M≤10000，一帧的特征个数满足 ≤ 10000。
 特征取值均为非负整数。

 输出描述:
 对每一个测试用例，输出特征运动的长度作为一行
 输入例子 1:
 1
 8
 2 1 1 2 2
 2 1 1 1 4
 2 1 1 2 2
 2 2 2 1 4
 0
 0
 1 1 1
 1 1 1

 输出例子 1:
 3

*/


/*
	 题解

	 hash
	 开辟两个map,一个用来保存当前帧的特征,一个用来保存上一帧的特征。
	 用hashmap比treemap更合理，但是C++的hashmap不能接受pair作为key转化为string即可

*/

#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> last;
unordered_map<string, int> cur;

string make_str(int x, int y) {
	return to_string((long long)x) + to_string((long long)y);
}

int N, M;
int main() {
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &M);
		int res = 1;
		while(M--) {
			int cnt;scanf("%d", &cnt);
			cur.clear();
			while(cnt--) {
				int x, y;scanf("%d%d",&x, &y);

				if (last.count(make_str(x, y))) {
					cur[make_str(x, y)] += (last[make_str(x, y)] + 1);
					res = max(res, cur[make_str(x, y)]);
				}
				else {
					cur[make_str(x, y)]++;
				}
			}
			last = cur;
		}
		last.clear();
		printf("%d\n", res);
	}
}

