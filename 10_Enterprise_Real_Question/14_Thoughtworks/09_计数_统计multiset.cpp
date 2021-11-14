

/*
 * Date:2021-11-14 09:00
 * filename:09_计数_统计multiset.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator()(map<int,int>::iterator lhs, map<int, int>::iterator rhs) {
		return lhs->second > rhs->second;
	}
};

void get_topK_number(vector<int>& nums) {
	if (nums.size() < 0) 
		return ;
	map<int, int> countmap;
	for (int i = 0; i < (int)nums.size();++i) {
		countmap[nums[i]]++;
	}
	
	//排序
	multiset<map<int, int>::iterator, compare> SortSet;
	map<int, int>::iterator ite = countmap.begin();

	while (ite != countmap.end()) {
		SortSet.insert(ite);
		++ite;
	}

	multiset<map<int, int>::iterator, compare>::iterator it1 = SortSet.begin();

	for (; it1 != SortSet.end();++it1) {
		cout << (*it1)->first << ":" << (*it1)->second << endl;
	}
}

void test_map_num() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);
	v.push_back(7);

	get_topK_number(v);
}

int main() {
	test_map_num();
}
