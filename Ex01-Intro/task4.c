#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

int64_t i = 0;

void* thread_1()
{
	for (int j = 0; j < 1000000; j++)
	{
		i++;
	}
	return NULL;
}

void* thread_2()
{
	for (int j = 0; j < 1000000; j++)
	{
		i--;
	}
	return NULL;
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, thread_1, NULL);
	pthread_create(&t2, NULL, thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("%i\n", (int32_t)i);
}