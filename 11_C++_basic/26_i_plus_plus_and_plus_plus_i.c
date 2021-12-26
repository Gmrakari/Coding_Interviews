

/*
 * Date:2021-12-26 08:31
 * filename:i_plus_plus_and_plus_plus_i.c
 *
 */

#include <stdio.h>

int main() {
	int i = 2;
	switch(i) {
		case 1: i++;
		case 2: i--;
		case 3: ++i;break;
		case 4: --i;
		default:
			i++;
	}
	printf("%d\n",i);
}

//2
//i-- -> 1
//case 3 : ++i -> i = 2
