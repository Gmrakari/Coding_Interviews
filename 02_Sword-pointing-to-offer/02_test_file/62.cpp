#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 * string to int 
 *
 */

#ifndef __GNUC__
//itoa is not the C programming language statand libray function,can not use in gcc
string IntToStringByitoa(int num)
{
	char *pstr = itoa(num);
	string str(pstr);
	cout << "int(" << num << ") to " << "str(" << str << ")" << endl;
	return str;
}
#endif

//use sprintf take any format information output to char *
string IntToStringBysprintf(int num)
{
	char pstr[81];
	sprintf(pstr,"%d",num);

	string str(pstr);

	cout << "int(" << num << ") to " << "str(" << str << ")" << endl;
	return str;
}

//use stringstream format string
string IntToStringBystringstream(int num)
{
	string str;
	stringstream ss;

	ss << num;
	ss >> str;

	cout << "int(" << num << ") to " << "str(" << str << ")" << endl;
	return str;
}

//use ostringstream take any format information conver into string(output)
string IntToStringByostringstream(int num)
{
	string str;
	ostringstream ss;

	ss << num;
	str = ss.str();
		
	cout << "int(" << num << ") to " << "str(" << str << ")" << endl;
	return str;
}


int main(int argc,const char* argv[])
{

#ifndef __GNUC__
	IntToStringByitoa(25);
#endif

	IntToStringBysprintf(25);
	IntToStringBystringstream(25);
	IntToStringByostringstream(25);

	return 0;
}


