
#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	int cnt =  0;
	for(i = 1; i <= 13;i++)
	{
		if( i == 1 )
		{
			cnt++;
			cout << i << " ";
		}
		else if(i < 10)
			continue;
		else{
			if( i / 10 == 1 )
			{
				cnt++;
				cout << i << " ";
			}
		}
	}
	cout << "cnt : " << cnt << endl;
}

