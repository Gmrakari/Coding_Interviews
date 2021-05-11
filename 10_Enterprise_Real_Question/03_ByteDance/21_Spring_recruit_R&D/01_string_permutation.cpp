

/*
 * Date:2021-05-11 19:47
 * filename:01_string_permutation.cpp
 *
 */

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int cnt_str(char *s1,int &n)
{
	if(s1 == nullptr || n < 0)	return 0;
	//int n1 = sizeof(s1) / sizeof(s1[0]);
	int n1 = strlen(s1);
	printf("n1 = %d",n1);
	cout << endl;
	if(n > n1) return 0;

	/*
	int cnt = 0;

	for(int i = 0;i < n1;i++)
	{
		for(int j = i + 1;j < n1;j++)
		{
			if(s1[i] == s1[j])
			{
				++cnt;
				if(cnt == n1) return 0;
			}
		}
	}
	*/

	int ret = 0;
	if(n1 > 0 && n1 <= 52)
	{
		return ret = n1 * (n1 - 1) >> (n - 1);
	}else
	{
		return 0;
	}
}

int main()
{
	int ret,n;
	char *s;
	cin >> s;
	//scanf("%s,%d",s,&n);
	scanf("%d",&n);
	printf("%d\n",ret = cnt_str(s,n));
	return 0;
}
