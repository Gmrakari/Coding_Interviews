

/*
 * Date:2021-08-17 17:42
 * filename:52_构建乘积数组.cpp
 *
 */


/*
#题意
题目描述

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]A[1]...*A[i-1]A[i+1]...*A[n-1]。

不能使用除法。

*/


void multiply(const vector<double>& array1, vector<double>& array2) {
	int length1 = array1.size();
	int length2 = array2.size();

	if (length1 == length2 && length2 > 1) {
		array2[0] = 1;
		for (int i = 1; i < length1; ++i) {
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		double tmp = 1;
		for (int i = length1 - 2; i >= 0; --i) {
			tmp *= array1[i + 1];
			array2[i] *= tmp;
		}
	}
}
