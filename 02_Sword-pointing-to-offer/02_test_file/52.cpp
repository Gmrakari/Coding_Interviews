#include <iostream>
#include <vector>
using namespace std;

/*

void multiply(const vector<double>& array1)
{
	vector<double> array2;
	int length1 = array1.size();
	int length2 = array2.size();
	int i = 0;
	if(length1 == length2 && length2 > 1)
	{
		array2[0] = 1;
		for(int i = 1;i < length1;i++)
		{
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		double temp = i;
		for(int i = length1 - 2; i >= 0;--i)
		{
			temp *= array1[i - 1];
			array2[i] *= temp;
		}
	}
	cout << "test:" << endl;

	for(vector<double>::iterator it = array2.begin();it != array2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

*/

vector<int> multiply_2(const vector<int>& A)
{
	int nlength1 = A.size();
	vector<int> res(nlength1);

	for(int i = 0,temp = 1;i < nlength1;i++)
	{
		res[i] = temp;
		temp *= A[i];
	}

	for(int i = nlength1 - 1, temp = 1;i >= 0;i--)
	{
		res[i] *= temp;
		temp *= A[i];
	}
	return res;
}

int main(int argc,const char* argv[])
{
	const vector<int> array1 = {1,2,3,4,5};
	int length = array1.size();
		
	vector<int> array2(length);

	array2 = multiply_2(array1);

	for(vector<int>::iterator it = array2.begin(); it != array2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
