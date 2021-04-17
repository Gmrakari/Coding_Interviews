/*
 * Date:2021-04-17 00:22
 * Author:Gmrakari
 * filename:混战世界
 */


/*
1、混战世界
【题目描述】
战乱年代，整个世界各个军阀的兵团混战，你是 PZ 军团的战略参谋，你手下有 n(保证为 3 的倍数)个士兵，
第 i 个士兵的物理攻击数值为 Ai，魔法攻击数值为Bi，你需要将这些士兵三等分为三个连，
第一个连需要去物理空间参加物理对抗战争，战斗力估值W1为士兵的物理攻击数值之和;
第二个连需要去魔法空间参加魔法对抗战争，战斗力估值W2 为士兵的魔法攻击数值之和;
第三个连需要去虚幻空间参加物理魔法兼备的综合对抗战争，战斗力估值W3为所有士兵的物理攻击数值、魔法攻击数值之和除以2。
你希望 W1+W2+W3 最大，这样才最有可能胜利。

输入描述:
第一行一个整数n保证为3的倍数。(3≤n≤100000)
第二行n个整数，第i个数表示 Ai。
第三行n个整数，第i个数表示 Bi。(1≤Ai, Bi≤1000)
输出描述:
一个小数，表示最大数值和，保留两位小数(四舍五入)。
输入样例:
6
1 7 3 4 5 9
2 3 9 4 3 3

输出样例: 35.00

*/

/*
 * 解题思路
 * 设一个人的物理值为A，魔法值为B
 * 派去一连可得A的贡献，二连可得(A + B) / 2，三连可得B。
 * 去一连与去二连相比差了A - (A + B) / 2 = (A - B) / 2,同理去二连比去三连也差了(A - B) / 2
 * 这样，可以根据每个人得A - B数值进行排序，较大者去一连，较小者去三连，中间的去二连.
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N],b[N],id[N],n;

inline bool cmp(int x,int y)
{
	return a[x] - b[x] > a[y] - b[y];
}

int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)
		scanf("%d",a + i);
	for(int i = 1;i <= n;++i)
		scanf("%d",b + i);
	for(int i = 1;i <= n;++i)
		id[i] = i;
	sort(id + 1,id + n + 1,cmp);
	int k = n / 3;
	long long ans = 0;
	for(int i = 1; i <= n;++i)
	{
		if(i <= k)
			ans += a[id[i]] * 2;
		else if(i <= k * 2)
			ans += a[id[i]] + b[id[i]];
		else
			 ans += b[id[i]] * 2;
	}

	printf("%.2f\n",ans / 2.0);
	return 0;
}
