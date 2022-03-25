#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


void* myThread(void* ptr)
{
	printf("My Thread\n");
	pthread_cancel(pthread_self());
	return NULL;
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, NULL, myThread, NULL); 
	pthread_join(thread, NULL); 
	return 0;
}
