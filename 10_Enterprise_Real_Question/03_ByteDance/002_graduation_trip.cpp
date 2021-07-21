

/*
 * Date:2021-05-09 18:41
 * filename:02_graduation_trip.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int dis[12][12],f[1<<12][12],pos[1<<12][12];

int main()
{
	int n;

	while(~scanf("%d",&n))
	{
		for(int i = 0; i < n;++i)
		{
			for(int j = 0;j < n;j++)
			{
				scanf("%d",&dis[i][j]);
			}
		}
		int b = 1 << (n - 1);

		memset(f,-1,sizeof(f));
		for(int i = 0;i < n;i++)
			f[0][i] = dis[i][0];
		for(int st = 1;st < b - 1;st++)
		{
			for(int i = 1;i < n;i++)
			{
				if(st & (1 << (i - 1))) continue;
				int minn = INF;
				for(int j = 1;j < n;j++)
				{
					if(st & (1 << (j - 1)))
					{
						int tmp = dis[i][j] + f[st^(1 << (j - 1))][j];
						if(tmp < minn)
						{
							minn = tmp;
							f[st][i] = tmp;
							pos[st][i] = j;
						}
					}
				}
			}
		}
		int minn = INF;
		for(int k = 1;k < n;k++)
		{
			int tmp = f[(b - 1)^(1 << (k - 1))][k] + dis[0][k];
			if(tmp < minn)
				minn = tmp,f[b - 1][0] = tmp,pos[b - 1][0] = k;
		}
		printf("%d\n",f[b - 1][0]);
	}
	return 0;
}
