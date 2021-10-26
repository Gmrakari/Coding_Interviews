

/*
 * Date:2021-10-26 11:13
 * filename:25_1_ofstream_文件输出流的使用.cpp
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream File1("text.txt");
	string d("20160314");
	string y = d.substr(0, 4);
	int k = d.find("2");
	int i = d.find("3");

	string m = d.substr(k + 2, i - k);
	string dd = d.substr(i + 1, 2);
	string n = dd + m + y;
	File1 << n << endl;
	File1.close();

}
