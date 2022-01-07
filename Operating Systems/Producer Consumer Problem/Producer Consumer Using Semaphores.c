#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>
#include <time.h>

#define Iterations 5
#define Size 3

sem_t empty;
sem_t full;
sem_t lock;
int in = 0;
int out = 0;
int buffer[Size] = {0};

void show()
{
    for (int i=0;i<Size;i++)
        printf("%d ",buffer[i]);
    printf("\n");
}

void* prod(void* _args)
{
    int item;
    for(int i=0;i<Iterations;i++)
    {
        sleep(rand() % 3);
        item = 1 + rand() % 10;
        sem_wait(&empty);
        sem_wait(&lock);
        buffer[in] = item;
        printf("\nProduced : %d",buffer[in]);
        printf("\nBuffer Status : ");
        show();
        if(buffer[0] != 0 && buffer[1] != 0 && buffer[2] != 0)
            printf("\n\nProducer Blocked as Buffer is Full\n\n");
        in = (in+1)%Size;
        sem_post(&full);
        sem_post(&lock);
    }
}

void* cons(void* _args)
{
    for(int i=0;i<Iterations;i++)
    {
        sleep(rand() % 3);
        sem_wait(&full);
        sem_wait(&lock);
        int item = buffer[out];
        buffer[out] = 0;
        printf("\nConsumed : %d",item);
        printf("\nBuffer Status : ");
        show();
        if(buffer[0] == 0 && buffer[1] == 0 && buffer[2] == 0)
            printf("\n\nConsumer Blocked as Buffer is Empty\n\n");
        out = (out+1)%Size;
        sem_post(&empty);
        sem_post(&lock);
    }
}

int main()
{
    pthread_t pro,con;
    sem_init(&lock,0,Size);
    sem_init(&empty,0,Size);
    sem_init(&full,0,0);
    pthread_create(&pro,NULL,prod,NULL);
    sleep(1);
    pthread_create(&con,NULL,cons,NULL);
    pthread_join(pro,NULL);
    pthread_join(con,NULL);
    sem_destroy(&lock);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
