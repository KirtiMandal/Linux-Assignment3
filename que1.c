#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


int var = 0;    

void* t_fun(void* args)
{
	var = 1;
	printf("var changed to -> %d\n", var); 
}

int main(){
		
	pthread_t tid;
	
	printf("var before thread call -> %d\n\n", var);
	int n = pthread_create(&tid, NULL, t_fun, NULL);
	
	if(n == 0)
		printf("thread created successfully\n\n");
	else
		printf("error\n\n");
	
	pthread_join(tid, NULL);
	
	pthread_exit(NULL); 
	
return 0;
}
}
