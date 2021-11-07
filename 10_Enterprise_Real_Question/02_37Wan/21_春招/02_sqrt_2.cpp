
/*
 * Date:2021-04-18 09:35
 * filename:不用库函数求sqrt(2),精确到小数点后10位
 */

#include <bits/stdc++.h>
using namespace std;
const double N = 0.0000000001;

double Solution_1(double &left,double &right)
{
	double mid;
	while(right > left)
	{
		mid = (left + right) / 2;
		double tmp = mid * mid  - 2;
		if(abs(tmp) <= N)
		{
			return mid;
		}
		else if(tmp < 0)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return mid;
}

namespace binary_search {
	class Solution {
		public:
			int BinarySearch_1(int target) {
				const int N = 10000000;
				int *arr = new int[N];
				int left = 0, right = (int)extent<decltype(arr, 0)>::value - 1;
				while (left <= right) {
					int mid = (left + right) / 2;
					if (arr[mid] == target) return mid;
					if (target > arr[mid])
						left = mid + 1;
					else if (target < arr[mid])
						right = mid - 1;
				}
				delete[] arr;
				return 0;
			}
			double BinarySearch_2(int target) {
				if (target == 0 || target == 1)
					return target;
				double C = target;
				double res = target;

				while (true) {
					double xi = 0.5 * (res + C / res);
					if (fabs(res - xi) < 1e-10) 
						break;
					res = xi;
				}
				return double(res);
			}

			double BinarySearch_3(int target) {
				if (target == 0 || target == 1)
					return target;
				double ans = exp(0.5 * log(target));
				return ((long long)(ans + 1) * (ans + 1) <= target ? ans + 1 :ans);
			}

			static float BinarySearch_4(float number) {
				volatile long i;
				volatile float x, y;
				volatile const float f = 1.5F;

				x = number * 0.5F;
				y = number;

				i = *((long *)&y);
				i = 0x5f375a86 - (i >> 1);
				y = *((float *)&i);
				y = y * (f - (x * y * y));
				return y * 2;
			}

			double BinarySearch_5(int target) {
				if (target == 0 || target == 1)
					return target;
				double left = 0, right = target, ans = -1;
				while (left <= right) {
					double mid = left + (right - left) / 2;
					if ((long long)mid * mid <= target) {
						ans = mid;
						left = mid + 1;
					}
					else {
						right = mid - 1;
					}
				}
				return ans;
			}
	};
}

void test() {
	binary_search::Solution A;
	int n = 2;
	float m = 2;
	cout << A.BinarySearch_1(n) << endl;
	cout << A.BinarySearch_2(n) << endl;
	cout << A.BinarySearch_3(n) << endl;
	cout << A.BinarySearch_4(m) << endl;
	cout << A.BinarySearch_5(n) << endl;
}


int main()
{
	double left = 1.4;
	double right = 1.5;
	double ret = Solution_1(left,right);
	cout << ret << endl;

	test();
	return 0;
}
