

/*
 * Date:2022-03-18 10:32
 * filename:30_判断是否为合法的ipv4地址.cpp
 *
 */

#include <string.h>
#include <iostream>
using namespace std;

bool isValidIpAddress(char *str) {
	int num, i, len;
	char *ch;

	//counting number of quads present in a given IP address
	int qnumberCnt = 0;
	len = strlen(str);

	//  Check if the string is valid
	if (len < 7 || len > 15) 
		return false;

	ch = strtok(str, ".");

	while (ch != NULL) {
		qnumberCnt++;
		num = 0;
		i = 0;

		//  Get the current token and convert to an integer value
		while (ch[i] != '\0') {
			num = num * 10;
			num = num + (ch[i] - '0');
			i++;
		}

		if (num < 0 || num > 255) 
			return false;

		if ((qnumberCnt == 1 && num == 0) || (qnumberCnt == 4 && num == 0)) 
			return false;

		ch = strtok(NULL, ".");
	}

	//  Check the address string, should be n.n.n.n format
	if (qnumberCnt != 4) 
		return false;

	return true;
}

int main() {
	char str[] = "192.255.1.1";

	if (isValidIpAddress(str)) 
		cout << "valid" << endl;
	else
		cout << "unvalid" << endl;
}
