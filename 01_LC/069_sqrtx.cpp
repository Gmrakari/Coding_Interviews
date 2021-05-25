

/*
 * Date:2021-05-23 14:54
 * filename:069_sqrtx.cpp
 *
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <type_traits>
#include <math.h>
#include <algorithm>
using namespace std;

/*
 * 21暑期实习 37互娱的笔试题第二题出现过
 * 当时没有做对 也没有想法 可能没有碰到 不知道二分查找的解法
 */

/*
 * 1-二分法
 * 2-牛顿迭代法
 * 3-袖珍计算器算法
 */

/*
 *
	//二分法模板

int BinarySearch(int target) {
	int *arr = new int[10];
	int left = 0,right = (int)extent<decltype(arr,0)>::value - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target) return mid;
		if (target > arr[mid]) 
			left = mid + 1;
		else if (target < arr[mid])
			right = mid - 1;
	}
	delete [] arr;
	return 0;
}

 *
 *
*/
/*
 *
class Solution {
public:
    int mySqrt(int x) {
			if (x == 0 || x == 1) return x;
			int l = 1, r = x, res;
			while (l <= r) {
				int m = (l + r) / 2;
				if (m == x / m) {
					return m;
				} else if (m > x / m) {
					r = m - 1;
				} else {
					l = m + 1;
					res = m;
				}
			}
			return res;
    }
};

*/

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0 || x == 1) return x;
		int left = 0, right = x, ans = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if ((long long)mid * mid <= x) {
				ans = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return ans;
	}
};


class Solution_2 {
public:
    int mySqrt(int x) {
			if (x == 0 || x == 1) return x;
			double C = x;
			double res = x;
			while (true) {
				double xi = 0.5 * (res + C / res);
				if (fabs(res - xi) < 1e-7) {
					break;
				}
				res = xi;
			}
			return int(res);
    }
};

class Solution_3 {
public:
	int mySqrt(int x) {
		if (x == 0 || x == 1) return x;
		int ans = exp(0.5 * log(x));
		return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
	}
};

/*
 * Author:Crazepony
 * update Date: 2021-05-25
 * 飞控代码
 * copy by:www.crazepony.com/book/bolg/2015-08-27-carmark-sqrt.html
 */
static float invSqrt(float number) {
	volatile long i;
	volatile float x, y;
	volatile const float f = 1.5F;

	x = number * 0.5F;
	y = number;

	i = *((long *)&y);
	i = 0x5f375a86 - (i >> 1);
	y = *((float *) &i);
	y = y * ( f - ( x * y * y ) );
	return y;
}
