

/*
 * Date:2021-10-09 20:50
 * filename:01_string_count.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;


string decodeString(string str) {
	// write code here
	if (str.length() < 0) return "";
	stack<char> st;
	string result = "";
	for (int i = 0; i < (int)str.length();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			int temp_num = str[i] - '0';
			if (str[i] == '[') {
				st.push(str[i]);
			}
			if (str[i] >= 'a' && str[i] <= 'z') {
				char temp_char = str[i];
				for (int i = 0; i < temp_num;i++) {
					result += temp_char; 
				}
			}
			if (str[i] == ']') {
				break;
			}
		}
	}
	return result;
}

string test(string str){ 
	int num = 0;
	queue<int> que;
	stack<char> st;
	string result;
	for (int i = 0; i < (int)str.length();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = str[i] - '0';
			que.push(num);
		}
	}
	for (int i = 0;i <(int)str.length();i++) {
		if (str[i] == '[') {
			continue;
		}
		if (str[i] != ']') {
			st.push(str[i]);
		}
	}
	int count = que.front();

	for (int i = 0;i < count;i++) {
		result += st.top();
		st.pop();
	}

	return result;

}

string my_fun() {
	string str = "ab";
	string ret = "";
	for (int i = 0; i < 3; i++) {
		ret += str;
	}
	return ret;
}

//模板ok Date:2021-10-09 对模板进行修改
string num_test() {
	string str = "3ab";
	string ret = "";
	string result = "";
	int temp_num;
	for (int i = 0; i < (int)str.length();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp_num = str[i] - '0';
			continue;
		}
		ret += str[i];
	}
	cout << "temp_num:" << temp_num << endl;
	for (int i = 0; i < temp_num;i++) {
		result += ret;	
	}
	return result;
}

string decodeString_16_precent(string str) {
	// write code here
	if (str.length() < 0) return "";
	stack<char> st;
	string result = "";
	for (int i = 0; i < str.length();i++) {
		result += str[i];
	}
	return result;
}


int main() {
	/*
		 string str = "3[a]";
		 str = test(str);
		 cout << str << endl;
		 */
	//cout << my_fun() << endl;
	cout << num_test() << endl;
	//cout << decodeString(str) << endl; 
}
