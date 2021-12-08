

/*
 * Date:2021-12-08 15:25
 * filename:26_order_print_to_50.c
 *
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;//互斥锁
int total;

void* ThreadProc_A(void* arg) {
	while(total < 50) {
		pthread_mutex_lock(&mutex);
		int cur = total;
		cur += 1;
		total = cur;
		printf("ThreadProc_A:%ld\t total:%d\n", pthread_self(), total);
		pthread_mutex_unlock(&mutex);
		usleep(rand() % 100);
	}
	return 0;
}

void* ThreadProc_B(void* arg) {
	while(total < 50) {
		pthread_mutex_lock(&mutex);
		int cur = total;
		cur += 1;
		total = cur;
		printf("ThreadProc_B:%ld\t total:%d\n", pthread_self(), total);
		pthread_mutex_unlock(&mutex);
		usleep(rand() % 100);
	}
	return 0;
}

int main() {

	pthread_mutex_init(&mutex, NULL);
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, ThreadProc_A, NULL);
	pthread_create(&tid2, NULL, ThreadProc_B, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&mutex);
	return 0;
}
