

/*
 * Date:2021-12-14 14:25
 * filename:fork().cpp
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int tid;
	int number = 1;

	tid = fork();

	if (tid > 0) {
		number++;
		printf("parent number:%d\t number address:%p\n",number, &number);
	}
	else if (tid == 0) {
		printf("child number:%d\t number address:%p\n", number, &number);
	}
	return 0;
}
