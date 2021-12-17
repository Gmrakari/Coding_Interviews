

/*
 * Date:2021-10-29 16:31
 * filename:12_数组全排列.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
class A {
	public:
		void permutation(vector<T> vec, T low, T high) {
			if (low == high) {
				for (int i = 0;i <= low;i++) {
					cout << vec[i];
				}
				cout << endl;
			}
			else {
				for (int i = low; i <= high;i++) {
					swap(vec[i], vec[low]);
					permutation(vec, low + 1, high);
					swap(vec[i], vec[low]);
				}
			}
		}

};
/*
	 void permutation(vector<int> vec, int low, int high) {
	 if (low == high) {
	 for (int i = 0;i <= low;i++) {
	 cout << vec[i];
	 }
	 cout << endl;
	 }
	 else {
	 for (int i = low; i <= high;i++) {
	 swap(vec[i], vec[low]);
	 permutation(vec, low + 1, high);
	 swap(vec[i], vec[low]);
	 }
	 }
	 }
	 */

vector<int> init() {
	vector<int> vec = {1,2,3};
	return vec;
}

vector<char> init_string() {
	vector<char> ret = {'a','b','c'};
	return ret;
}

/*
 * Update:2021-11-06
 * Permutation using C
 */


void realize_permutation(char *pstr, char* pBegin) {
	if (*pBegin == '\0')
		printf("%s\n",pstr);
	else {
		for (char* pch = pBegin;*pch != '\0';++pch) {
			char temp = *pch;
			*pch = *pBegin;
			*pBegin = temp;
			realize_permutation(pstr, pBegin + 1);
			temp = *pch;
			*pch = *pBegin;
			*pBegin = temp;
		}
	}
}

void permutation_c(char *pstr) {
	void realize_permutation(char *pstr, char* pBegin);
	if (pstr == NULL)
		return ;
	realize_permutation(pstr, pstr);
}

int main() {
	vector<int> ret = init();
	A<int> test;
	test.permutation(ret, 0, ret.size() - 1);

	cout << endl;
	vector<char> ret_char = init_string();
	A<char> test2;
	test2.permutation(ret_char, 0, ret_char.size() - 1);

	cout << endl;
	char str[] = "abc";
	permutation_c(str);

	return 0;
}
