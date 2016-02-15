#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>

#define ITER 10000

int32_t i = 0;
sem_t mutex;

void* thread_1()
{
	for (int j = 0; j < ITER; j++)
	{
		sem_wait(&mutex);
		//printf("Thread 1\n");
		i++;
		sem_post(&mutex);
	}
	printf("t1 completed\n");
	return NULL;
}

void* thread_2()
{
	for (int j = 0; j < ITER; j++)
	{
		sem_wait(&mutex);
		//printf("Thread 2\n");
		i--;
		sem_post(&mutex);
	}
	printf("t2 completed\n");
	return NULL;
}

int main()
{
	sem_init(&mutex, 0, 1);

	pthread_t t1;
	pthread_t t2;

	printf("Starting t1\n");
	pthread_create(&t1, NULL, thread_1, NULL);
	printf("Starting t2\n");
	pthread_create(&t2, NULL, thread_2, NULL);	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("%i\n", (int32_t)i);
}