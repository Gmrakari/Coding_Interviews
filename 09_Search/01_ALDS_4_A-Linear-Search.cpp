
/*
 * Date:2021-04-17 18:22
 * filename:Linear Search
 */

/*
 * 请编写一个程序，输入包含n个整数的数列S以及包含q个不重复整数的数列T，输出即包含于T也包含于S的整数的个数C。
 *
 * 输入 
 * 第1行输入n，
 * 第2行输入代表S的n个整数，
 * 第3行输入q，
 * 第4行输入代表T的q个整数。
 *
 * 输出
 * 用1行输出C。
 *
 */
/*

输入示例
5
1 2 3 4 5
3
3 4 1
输出示例
3

*/

/*
 * 通过现性搜索来检查数列S中是否包含T的各元素.线性搜索可以用for循环来实现
 */

#include <bits/stdc++.h>
using namespace std;

int search(int A[],int n,int key)
{
	int i = 0;
	A[n] = key;
	while(A[i] != key) i++;
	return i != n;
}

int main()
{
	int i,n,A[10000 + 1],q,key,sum = 0;

	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&A[i]);

	scanf("%d",&q);
	for(i = 0;i < q;i++)
	{
		scanf("%d",&key);
		if(search(A,n,key)) sum++;
	}
	printf("%d\n",sum);
	
	return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec1;
	int sum = 0;

	int n;
	cin >> n;
	int tmp1;
	for(int i = 0;i < n;i++)
	{
		cin >> tmp1;
		vec1.push_back(tmp1);
	}

	int q;
	cin >> q;
	vector<int> vec2;
	int tmp2;
	for(int i = 0;i < q;i++ )
	{
		cin >> tmp2;
		vec2.push_back(tmp2);
	}
	
	for(vector<int>::iterator it1 = vec1.begin();it1 != vec1.end();it1++)
	{
		for(vector<int>::iterator it2 = vec2.begin();it2 != vec2.end();it2++)
		{
			if(*it1 == *it2)
			{
				sum++;
			}
		}
	}
	cout << sum << endl;

	return 0;
}
*/
