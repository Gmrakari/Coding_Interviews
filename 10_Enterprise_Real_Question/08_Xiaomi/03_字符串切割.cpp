

/*
 * Date:2021-08-14 09:26
 * filename:string.cpp
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1] ; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}

	return res;
}

int ToInt(const string &str) {
	return atoi(str.c_str());
}

int main() {
	std::string str;

	std::string pattern = " ";
	getline(std::cin, str);

	std::vector<string> ret = split(str, pattern);

	for (int i = 0; i < (int)ret.size();i++) {
		std::cout << ret[i];
	}

	vector<int> _score;
	std::transform(ret.begin(), ret.end(), std::back_inserter(_score), ToInt);

	cout << endl;
	for (int i = 0; i < (int)_score.size();i++) {
		cout << _score[i];
	}
	cout << endl;
}
