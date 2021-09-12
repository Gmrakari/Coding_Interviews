

/*
 * Date:2021-09-12 10:43
 * filename:02_my_atoi.cpp
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int my_atoi(const char *str) {
	int total = 0;
	int isNegative = 0;
	int length = 0;
	const char* p = str;
	char temp = '0';

	if (p == NULL) {
		printf("error");
		return -1;
	}

	while (*p++ != '\0') {
		++length;
	}

	p = str;

	if (*p == '-') {
		isNegative = -1;
	}

	for (int i = 0; i < length; ++i) {
		temp = *p++;
		if (temp > '9' || temp < '0') {
			continue;
		}
		if (total != 0 || temp != '0') {
			temp -= '0';
			total = total * 10 + temp;
		}
	}

	if (isNegative) 
		return (0 - total);
	else 
		return total;
}

int main() {
	cout << "my_atoi(" << "-12321" <<"):";
	printf("%d\n", my_atoi("-12321"));

	cout << "my_atoi(" << "987654210" <<"):";
	printf("%d\n", my_atoi("987654210"));
	return 0;
}
