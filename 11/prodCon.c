#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mutex;
sem_t empty, full;
int in=0, out=0, buffer[5];

void *producer(void *pno){
	for(int i=0;i<5;i++){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		int x = rand()%100;
		buffer[in]=x;
		in = (in+1)%5;
		printf("Producer %d has put %d in buffer\n",*((int*)pno), x);
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void* cno){
	for(int i=0;i<5;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int x = buffer[out];
		out = (out+1)%5;
		printf("Comsumer %d has consumed %d\n",*((int*)cno), x);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

void main(){
	pthread_t prod[5], con[5];
	sem_init(&empty,0,10);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	
	int a[] = {1,2,3,4,5};
	
	for(int i=0;i<5;i++){
		pthread_create(&prod[i],NULL,(void*)producer, (void*)&a[i]);
		pthread_create(&con[i],NULL,(void*)consumer, (void*)&a[i]);
	}
	
	for(int i=0;i<5;i++){
		pthread_join(prod[i],NULL);
		pthread_join(con[i],NULL);
	}
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}







