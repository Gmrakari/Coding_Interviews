

/*
 * Date:2021-12-17 15:57
 * filename:01_fork_output.c
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int i;
    for (i = 0; i < 2; i++) {
        fork();
        printf("-");
    }
    return 0;
}
