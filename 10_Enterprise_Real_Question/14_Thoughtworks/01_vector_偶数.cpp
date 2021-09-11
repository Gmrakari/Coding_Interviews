

/*
 * Date:2021-09-11 20:32
 * filename:jioushu.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;

template <class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

class Solution {
	public:
		vector<int> odd(vector<int> array) {
			auto it = array.begin();
			for (it = array.begin(); it != array.end(); it++) {
				if ((*it) & 1) {
					array.erase(it);
				}
			}
			return array;
		}
		vector<int> odd_2(vector<int>& array){
			int j = 0;
			for (int i = 0; i < (int)array.size();++i) {
				if (array[i] % 2 != 0) {
					array[j++] = array[i];
				}	
			}
			return array;
		}

		void print(vector<int>& vec) {
			for (auto it = vec.begin(); it != vec.end(); it++) {
				cout << *it << ' ';
			}
			cout << endl;
		}
};

int main() {
	vector<int> vec = {1,2,3,4,5,6,7,8};
	vector<int> my_te;

	/*
		 my_te = odd(vec);

		 for_each(my_te.begin(), my_te.end(),display<int>());
		 cout << endl;

*/

	/*
	for_each(vec.begin(), vec.end(),display<int>());
	cout << endl;

	*/

	Solution fun1;
	fun1.odd_2(vec);
	fun1.print(vec);


	fun1.odd(vec);
	fun1.print(vec);

}
