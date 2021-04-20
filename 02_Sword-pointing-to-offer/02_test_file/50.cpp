#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/*
 * Date:2021-03-15
 * Author:Gmrakari
 * Filename:51.cpp
 */

bool duplicate_1(int numbers[],int length,int* duplication)
{
	if(numbers == nullptr || length < 0 || duplication == NULL)
		return false;

	for(int i = 0;i < length;++i)
	{
		if(numbers[i] < 0 || numbers[i] > length -1 )
			return false;
	}

	for(int i = 0;i < length;++i)
	{
		while( numbers[i] != i )
		{
			if(numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

bool duplicate(int numbers[],int length,int* duplication)
{
	unordered_map<int,int> unmp;
	unmp.reserve(length);

	for(int i = 0;i < length;++i)
	{
		if(unmp.find(numbers[i]) == unmp.end())
		{
			unmp.insert({numbers[i],1});
		}
		else
		{
			*duplication = numbers[i];
			return true;
		}
	}
	return false;
}

int main(int argc,const char* argv[])
{
	bool duplicate(int numbers[],int length,int* duplication);
	int numbers[] = {2,3,1,0,2,5,3};
	int len = sizeof(numbers) / sizeof(*numbers);
//	int num = 3;
	int num = 0;
	
	int num2 = 2;



	bool ret = duplicate_1(numbers,len,&num);
	cout << "ret: " << ret << endl;

	bool duplicate(int numbers[],int length,int* duplication);
	bool res = duplicate(numbers,len,&num);
	cout << "res: " << res << endl;
	res = duplicate(numbers,len,&num2);

	cout << "res: " << res << endl;
 


}
