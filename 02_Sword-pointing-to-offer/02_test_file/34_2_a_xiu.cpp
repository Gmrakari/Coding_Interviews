
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GetUglyNumber_Solution(int index)
{
	if( index < 7 ) return index;

	vector<int> result(index,0);
	result[0] = 1;

	int index_2 = 0,index_3 = 0,index_5 = 0;
	for(int i = 1;i < index;++i)
	{
		int minNum = min(min(result[index_2] * 2,result[index_3] * 3),result[index_5] * 5);
		if(minNum == result[index_2] * 2) index_2++;
		if(minNum == result[index_3] * 3) index_3++;
		if(minNum == result[index_5] * 5) index_5++;
		result[i] = minNum;
	}
	return result[index - 1];
}

int main()
{
	
	int GetUglyNumber_Solution(int index);
	int ret = GetUglyNumber_Solution(7);
	cout << ret << endl;

	ret = GetUglyNumber_Solution(1500);
	cout << ret << endl;
}
