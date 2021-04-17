
/*
 * Date:2021-04-17 19:45
 * filename:Binary Search
 */

/*
 *
请编写一个程序，输入包含n个整数的数列S以及包含q个不重复整数的数列T，输出既包含于T也包含于S的整数的个数C。
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

#include <bits/stdc++.h>
using namespace std;
int A[1000000],n;

int binarySearch(int key)
{
	int left = 0;
	int right = n;
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(key == A[mid]) return 1;
		if(key > A[mid]) left = mid + 1;
		else if(key < A[mid]) right = mid;
	}
	return 0;
}

int main()
{
	int i,q,key,sum = 0;
	
	cin >> n;
	for(int i = 0; i < n;i++)
	{
		cin >> A[i];
	}

	cin >> q;
	for(int i = 0;i < q;i++)
	{
		cin >> key;
		if(binarySearch(key)) sum++;
	}
	cout << sum << endl;
	return 0;
}

