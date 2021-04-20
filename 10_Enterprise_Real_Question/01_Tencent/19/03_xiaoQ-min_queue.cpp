
/*
 * Date:2021-04-20 14:08
 * filename:3-小 Q 的最小值序列
 */

/*
 *
【题目描述】
小 Q 得到了一个长度为 n 的序列 A，A 中的数各不相同。对于 A 中的每一个
数 Ai，求：min(1≤j<i)|Ai−Aj|
以及令上式取到最小值的 j（记为 P_i）。若最小值点不唯一，则选择使 Aj 较小的那个。

输入描述:
第一行一个整数 n，第二行 n 个数。

输出描述:
n-1 行，每行 2 个用空格隔开的整数。分别表示当 i 取 2~n 时，对应的 min(1≤j<i)|Ai−Aj|和 Pi
的值

输入样例：
3
1 5 3
输出样例：
4 1
2 1

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

struct P
{
	int value;
	int pos;
};

P a[N];
int cmp(P x,P y)
{
	return x.value < y.value;
}

int b[N],b2[N],cnt,head,tail,ans1[N],ans2[N];

struct node
{
	int value;
	int next,pre;
}e[N];

void init()
{
	cnt = 2;
	head = 1,tail = 2;
	e[head].next = tail;
	e[tail].pre = head;
}

void ins(int pos,int x)
{
	e[++cnt].value = x;
	e[cnt].next = e[pos].next;
	e[cnt].pre = pos;
	e[e[pos].next].pre = cnt;
	e[pos].next = cnt;
}

void del(int pos)
{
	e[e[pos].next].pre = e[pos].pre;
	e[e[pos].pre].next = e[pos].next;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",&a[i].value);
			a[i].pos = i;
	}

	sort(a + 1,a + 1 + n,cmp);

	init();
	for(int i = 1;i <= n;++i)
	{
		ins(e[tail].pre,a[i].value);
		b[a[i].pos] = cnt;
		b2[cnt] = a[i].pos;
	}

	for(int i = n;i >= 2;--i)
	{
		ans1[i] = inf;
		if(e[b[i]].next != tail)
		{
			ans1[i] = min(ans1[i],abs(e[b[i]].value - e[e[b[i]].next].value));
			ans2[i] = b2[e[b[i]].next];
		}
		if(e[b[i]].pre != head)
		{
			if(ans1[i] >= abs(e[b[i]].value - e[e[b[i]].pre].value))
			{
				ans1[i] = abs(e[b[i]].value - e[e[b[i]].pre].value);
				ans2[i] = b2[e[b[i]].pre];
			}
		}
		del(b[i]);
	}
	for(int i = 2;i <= n;++i)
		printf("%d %d\n",ans1[i],ans2[i]);

	return 0;
}
