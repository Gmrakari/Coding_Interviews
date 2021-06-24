

/*
 * Date:2021-06-24 07:19
 * filename:delete-the-same-numbers-in-vector.cpp
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int delete_same_number(vector<int>& vec) {
	int m = 0;
	for (int i = 0; i < (int)vec.size(); i++) {
		int j = 0;
		for (; j < m;++j) {
			if(vec[i] == vec[j])
				break;
		}
		if (j == m) {
			vec[m++] = vec[i];
		}
	}
	for (int i = 0;i < m;++i) {
		printf("%d%c",vec[i], i == m - 1 ? '\n' : ' ');
	}
	return 0;
}

static int n = 0;

vector<int> delete_same_number_2(vector<int>& array,int len) {
	for (int i = 0; i < len - n;i++) {
		for (int j = i + 1;j < len - n;j++) {
			if (array[i] == array[j]) {
				for (int k = j;k < len - n;k++) {
					array[k] = array[k + 1];
				}
				j--;
				n++;
			}
		}
	}
	return array;
}

void print(vector<int>& vec){
	for (int i = 0; i < (int)vec.size() - n;i++) {
		printf("%d%c",vec[i], i == (int)vec.size() - 1 ? '\n':' ');
	}
}

int main() {
	vector<int> vec = {1,2,6,4,5,6,6,2,1,1,9};
	int len = vec.size();

	int delete_same_number(vector<int>& vec);
	vector<int> delete_same_number_2(vector<int>& array,int len);
	void print(vector<int>& vec);

	print(vec);

	cout << "delete_same_number:" << endl;
	delete_same_number(vec);

	cout <<"delete_same_number_2:" << endl;
	delete_same_number_2(vec,len);
	print(vec);
	cout << endl;


}
