#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

//using 'count' to show the synchronization because of mutex because it helps to understand synchronized access of resources 
pthread_t tid[2];
int count;
pthread_mutex_t lock;

void* myFunc(void* arg)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	count += 1;
	printf("\nThread %d using resources\n", count);

	for (i = 0; i < (0xFFFFFFFF); i++)
		;

	printf("\nThread %d has finished and not using resources any more\n", count);

	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n Mutex could not be applied to the thread\n");
		return 1;
	}
	while (i < 2) {
		error = pthread_create(&(tid[i]),NULL,&myFunc, NULL);
		if (error != 0)
			printf("\nError :[%s] and hence thread can't be created",
				strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}

