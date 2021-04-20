#include <iostream>
#include <cstdlib>
using namespace std;

bool IsContinuous(int* numbers,int length)
{

	int compare(const void *arg1,const void *arg2);
	if(numbers == NULL || length < 1)
		return false;

	qsort(numbers,length,sizeof(int),compare);

	int numberOfZero = 0;
	int numberofGap = 0;

	for(int i = 0; i < length && numbers[i] == 0;++i)
	{
		++numberOfZero;
	}

	//count the gap
	int small = numberOfZero;
	int big = small + 1;
	while(big < length)
	{
		//two numbers equal,it is not a continuous array
		if(numbers[small] == numbers[big])
			return false;

		numberofGap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}
	return (numberofGap > numberOfZero) ? false : true;
}

int compare(const void *arg1,const void *arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}


int main(int argc,const char* argv[])
{

	bool IsContinuous(int* numbers,int length);
	int number[] = {3,5,1,0,4};
	int number1[] = {3,5,7,4,8};
	int len = sizeof(number) / sizeof(*number);

	cout <<	IsContinuous(number,len) << endl;
	cout <<	IsContinuous(number1,len) << endl;
}
