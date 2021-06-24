

/*
 * Date:2021-06-24 19:56
 * filename:03_仿LISP运算.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

/*
class Solution {
public:
	void calculatorLISP(string str) {
		stack<int> numStack;
		stack<string> operStack;
		int mark = 0;
		int paramOne = 0;
		int paramTwo = 0;
		for (int i = 0;i < (int)str.size();i++) {
			char c = str[i];
			if ( c == '(' ) {
				operStack.push(str.substr(i + 1, i + 4));
				i += 4;
				mark = i + 1;
			} else if (c == ')') {
				if (mark < i) {
					string tmp = str.substr(mark,i);
					int int_tmp = atoi(tmp.c_str());
					numStack.push(int_tmp);
					i++;
					mark = i + 1;
				}
				//paramTwo = numStack.pop();
				paramTwo = numStack.top();
				//paramOne = numStack.pop();
				paramOne = numStack.top();
				calc(numStack, operStack, paramOne, paramTwo);
			}
			else {
				if (c == ' ') {
					if (mark < i) {
						string tmp2 = str.substr(mark, i);
						int int_tmp_2 = atoi(tmp2.c_str());
						numStack.push(int_tmp_2);
						mark = i + 1;
					}
				}
			}
		}
		while ( !operStack.empty() ) {
			//paramTwo = numStack.pop();
			paramTwo = numStack.top();
			//paramOne = numStack.pop();
			paramOne = numStack.top();
			calc(numStack, operStack, paramOne,paramTwo);
		} 
		//cout << numStack.pop() << endl;
		cout << numStack.top() << endl;
	}
	void calc(stack<int>& numStack, stack<string>& operStack, int paramOne, int paramTwo) {
		//switch(operStack.pop()) {
		string tmp = operStack.top();
		char *p = tmp.c_str();
		if (!strcmp(tmp, "add")) {
			numStack.push(paramOne + paramTwo);
		} else if (!strcmp(tmp, "sub")) {
				numStack.push(paramOne - paramTwo);
		} else if (!strcmp(tmp,"mul")) {
				numStack.push(paramOne * paramTwo);
		} else if (!strcmp(tmp, "div")) {
			if (paramTwo == 0) {
				cout << "error" << endl;
			} else {
					numStack.push(paramOne / paramTwo);
			}
		} else {

		}

		
	//	switch(tmp) {
	//		case "add":
	//			numStack.push(paramOne + paramTwo);
	//			break;
	//		case "sub":
	//			numStack.push(paramOne - paramTwo);
	//			break;
	//		case "mul":
	//			numStack.push(paramOne * paramTwo);
	//		case "div":
	//			if (paramTwo == 0) {
	//				cout << "error" << endl;
	//			} else {
	//				numStack.push(paramOne / paramTwo);
	//			}
	//			break;
	//	}
	}
};

int main() {
	string s;
	cin >> s;
	Solution so;
	so.calculatorLISP(s);
}

*/


int main() {
	int mark = 0;
	int num1,num2;
	string str;
	stack<int> numStack;
	stack<string> operStack;
	getline(cin,str);
	for (int i = 0; i < (int)str.length();i++) {
		char c = str[i];
		cout << c << " ";
		if ( c == '(' ) {
			operStack.push(str.substr(i + 1,3));
			i += 4;
			mark = i + 1;
		} else if (c == ')') {
				if (mark < i) {
					numStack.push(stoi(str.substr(mark, i - mark)));
					i++;
					mark = i + 1;
				}
				num1 = numStack.top();
				numStack.pop();
	
				num2 = numStack.top();
				numStack.pop();

				string ex = operStack.top();
				operStack.pop();

				if(ex == "add") {
					numStack.push(num1 + num2);
				}
				else if ( ex == "sub" ){
					numStack.push(num1 - num2);
				}
				else if (ex == "mul") {
					numStack.push(num1 * num2);
				}
				else if (ex == "div") {
					if(num2 == 0) {
						cout << "error" << endl;
					}else {
						numStack.push(num2 / num1);
					} 
				}
			}
			else {
				if (c == ' ') {
					if (mark < i) {
						numStack.push(stoi(str.substr(mark, i - mark)));
						mark = i + 1;
					}
				}
			}
		}	
		cout << "res:";
		cout << numStack.top() << endl;
		return 0;
}
