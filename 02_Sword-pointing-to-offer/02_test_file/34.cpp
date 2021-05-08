#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;


bool IsUgly(int number)
{
	while(number % 2 == 0)
		number /= 2;
	while(number % 3 == 0)
		number /= 3;
	while(number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

int GetUglyNumber(int index)
{
	if(index <= 0)
		return 0;
	int number = 0;
	int uglyFound = 0;
	while(uglyFound < index)
	{
		++number;

		if(IsUgly(number))
		{
			++uglyFound;
		}
	}
	return number;
}

int GetUglyNumber_Solution2(int index)
{

	int Min(int number1,int number2,int number3);

	if(index <= 0)
		return 0;

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	
	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while(nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2,*pMultiply3 * 3,*pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
				++pMultiply2;
		while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
				++pMultiply3;
		while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
				++pMultiply5;

		++nextUglyIndex;
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int Min(int number1,int number2,int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}

int main(int argc,char* argv[])
{
	bool IsUgly(int number);
	int GetUglyNumber(int index);
	int ret = 0;

	ret = GetUglyNumber(7);
	cout << ret << endl;

	ret = GetUglyNumber_Solution2(7);
	cout << ret << endl;
	
}