#include <iostream>
using namespace std;

bool FindNumbersWithSum(int data[],int length,int sum,int* num1,int* num2)
{
	bool found = false;
	if(length < 1 || num1 == NULL || num2 == NULL)
		return found;

	int ahead = length - 1;
	int behind = 0;

	while(ahead > behind)
	{
		long long CurSum = data[ahead] + data[behind];
		if(CurSum == sum)
		{
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		}
		else if(CurSum > sum)
			ahead--;
		else
			behind++;
	}
	return found;
}

int main(int argc,const char* argv[])
{
	bool FindNumbersWithSum(int data[],int length,int sum,int* num1,int* num2);
	int data[] = {1,2,4,7,11,15};
	int len = sizeof(data)/sizeof(*data);
	int num1;
	int num2;

	FindNumbersWithSum(data,len,15,&num1,&num2);
	cout << "num1 : " << num1 << endl << "num2: " << num2 << endl;
}
