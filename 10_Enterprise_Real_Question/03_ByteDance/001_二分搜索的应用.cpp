

/*
 * Date:2021-06-20 20:50
 * filename:01_binary_search_application.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 99997867;
class Solution {
public:
	int clac(int N, int D, vector<int>& position) {
		int count = 0;
		int X,low,high,j,mid,a,b;
		for (int i = 0; i < N;i++) {
			X = position[i] + D;
			low = i + 1;
			high = N - 1;
			j = -1;
			while ( low <= high ) {
				mid = low + (high - low) / 2;
				if (position[mid] > X) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			j = high;
			if ((j - i - 1) > 0) {
				a = (j - i) % MOD;
				b = (j - i - 1) % MOD;
				count += (a + b) / 2;
			} 
		}
		return count % MOD;
	}
};

int main() {
	Solution su;

	int N,D;
	cin >> N;
	cin >> D;

	int tmp;
	vector<int> vec;
	for(int i = 0;i < N;i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	cout << su.clac(N,D,vec) << endl;

	/*
	 * 
res_1:
 input
	 5 19
	 1 10 20 30 50
 output:
 	 1 
	ac
res_2:
 input
	4 3
	1 2 3 4
 output
	3
	unac
  
	*/

}
