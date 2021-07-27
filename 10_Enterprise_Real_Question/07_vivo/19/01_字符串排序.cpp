

/*
 * Date:2021-07-27 14:30
 * filename:01_字符串排序.cpp
 *
 */

/*
 *
 【题目描述】
 请对一组字符串进行排序，字符串由大小写字母和数字组成，需要满足以下比较规则
 1、长度不同时，长度较短在排前面
 2、长度相同时，按照字典顺序排列(AaBb - Zz，0-9 顺序)，即大写字母在小写字母前，数字排在字母后。
 要求时间复杂度为 O(nlogn)。
 比如：
 abc Abc 123 1 1bc CBD abcd a
 排序后结果为：
 a 1 Abc abc CBD 1bc 123 abcd

*/

/*
 * 解题思路:
 * 按照题目要求实现cmp函数,调用sort函数
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct comparefun {
	int operator()(string s1, string s2) {
		string str1 = s1;
		string str2 = s2;

		int temp = str1.length() - str2.length();
		if (temp == 0) {
			int t1 = 0;
			int t2 = 0;
			for (int i = 0; i < (int)str1.length(); i++) {
				char c1 = str1[i];
				char c2 = str2[i];

				if (c1 >= 'A' && c1 <= 'Z') {
					t1 = (c1 - 'A') * 2 + 32;
				}
				else if (c1 >= 'a' && c1 <= 'z') {
					t1 = (c1 - 'a') * 2 + 33;
				}
				else if (c1 >= '0' && c1 <= '9') {
					t1 = c1 + 36;
				}
				if (c2 >= 'A' && c2 <= 'Z') {
					t2 = (c2 - 'A') * 2 + 32;
				}
				else if (c2 >= 'a' && c2 <= 'z') {
					t2 = (c2 - 'a') * 2 + 33;
				}
				else if (c2 >= '0' && c2 <= '9') {
					t2 = c2 + 36;
				}

				if ( t1 != t2 ) 
					break;
			}
			return t1 - t2;
		}
		else {
			return temp;
		}
	}
};

void test() {
	string arr[] =  {"abc","Abc","123","1","1bc","CBD","abcd","a"};
	int length = sizeof(arr) / sizeof(arr[0]);
	std::set<string, comparefun> s;

	cout << "original:";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < length; i++) {
		s.insert(arr[i]);
	}
	cout << "after:";
	for (auto ite = s.begin(); ite != s.end(); ite++) {
		cout << *ite << " ";
	}
	cout << endl;

	cout << "expected:";
	cout << "a 1 Abc abc CBD 1bc 123 abcd" << endl;
}

class transfer_java{
public:
	void run() {
		string input[] =  {"abc", "Abc", "123", "1", "1bc", "CBD", "abcd", "a" };
		
		cout << "original:";	
		for (auto s : input) {
			cout << s << ' ';
		}
		cout << endl;

		sort(input);

		cout << "after:";
		for (auto s : input) {
			cout << s << ' ';
		}
		cout << endl;

			
	}
	
	void sort(string input[]) {
		quickSort(input, 0, input->length() - 1);
	}

	void quickSort(string input[], int left, int right) {
		if (left > right) 
			return;

		int i, j;
		string t, tmp;
		tmp = input[left];
		i = left;
		j = right;

		while (i != j) {
			while (cmp(input[j], tmp) >= 0 && i < j) {
				j--;
			}
			while (cmp(input[i], tmp) <= 0 && i < j) {
				i++;
			}
			if (i < j) {
				t = input[i];
				input[i] = input[j];
				input[j] = t;
			}
		}
		input[left] = input[i];
		input[i] = tmp;
		quickSort(input, left, i - 1);
		quickSort(input, i + 1, right);

	}

	int cmp(string left, string right) {
		if (left.length() != right.length()) {
			return left.length() - right.length();
		}

		int len = left.length();
		for (int i = 0; i < len; i++) {
			char l = left[i];
			char r = right[i];
			if (l == r) {
				continue;
			}
			int lcv = getCharValue(l);
			int rcv = getCharValue(r);
			if (lcv != rcv) {
				return lcv - rcv;
			}
		}
		return 0;
	}
	
	int getCharValue(char c) {
		if (c >= 'a') {
			return (c - 'a') * 2 + 1;
		}
		else if(c >= 'A') {
			return (c - 'A') * 2;
		}
		return c - '0' + 52;
	}
};

int main() {
	void test();
	//test();
	transfer_java m_test;
	m_test.run();
}
