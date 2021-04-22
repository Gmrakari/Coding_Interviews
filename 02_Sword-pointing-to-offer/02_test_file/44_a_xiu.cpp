#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

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

bool IsContinuous_2(vector<int> numbers)
{
	int len = numbers.size();

	if( len < 5 ) return false;
	
	sort(numbers.begin(),numbers.end());
	for(int i = 0;i < len;++i)
	{
		cout << numbers[i] <<  " ";
	}
	cout << endl;
	int numOfZero = 0,numOfGap = 0;

	for(int i = 0; i < len;++i)
	{
		if(numbers[i] == 0) ++numOfZero;
		else if(numbers[i] == numbers[ i + 1 ]) 
		{
			return false;
		}
		else
		{
			numOfGap += numbers[i + 1] - numbers[i] - 1;
		}
		cout << "numOfZero " << numOfZero  << " " << "numOfGap " << numOfGap << endl;
	}
	return (numOfZero - numOfGap >= 0 ? true : false); 
}


int main(int argc,const char* argv[])
{

	bool IsContinuous(int* numbers,int length);
	int number[] = {3,5,1,0,4};
	int number1[] = {3,5,7,4,8};

	vector<int> number3;

	number3.push_back(3);
	number3.push_back(5);
	number3.push_back(1);
	number3.push_back(0);
	number3.push_back(4);

	vector<int> number4;
	number4.push_back(3);
	number4.push_back(5);
	number4.push_back(7);
	number4.push_back(9);
	number4.push_back(8);

	vector<int> number5{3,5,7,9,8};

	int len = sizeof(number) / sizeof(*number);

	cout <<	IsContinuous(number,len) << endl;
	cout <<	IsContinuous(number1,len) << endl;

	bool IsContinuous_2(vector<int> numbers);

	cout << "number3:" << endl << IsContinuous_2(number3) << endl;
	cout << "number4:" << endl << IsContinuous_2(number4) << endl;
	cout << "number5:" << endl << IsContinuous_2(number5) << endl;
}
