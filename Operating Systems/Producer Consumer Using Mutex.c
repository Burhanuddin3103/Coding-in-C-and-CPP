#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define Iterations 5
#define Size 3

int in = 0;
int out = 0;
int buffer[Size] = {0};
pthread_mutex_t mutex;

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
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("\nProduced : %d",buffer[in]);
        printf("\nBuffer Status : ");
        show();
        if(buffer[0] != 0 && buffer[1] != 0 && buffer[2] != 0)
            printf("\n\nProducer Blocked as Buffer is Full\n\n");
        in = (in+1)%Size;
        pthread_mutex_unlock(&mutex);
    }
}
void* cons(void* _args)
{
    for(int i=0;i<Iterations;i++)
    {
        sleep(rand() % 3);
        int item = buffer[out];
        pthread_mutex_lock(&mutex);
        buffer[out] = 0;
        printf("\nConsumed : %d",item);
        printf("\nBuffer Status : ");
        show();
        if(buffer[0] == 0 && buffer[1] == 0 && buffer[2] == 0)
            printf("\n\nConsumer Blocked as Buffer is Empty\n\n");
        out = (out+1)%Size;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t pro,con;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&pro,NULL,prod,NULL);
    sleep(1);
    pthread_create(&con,NULL,cons,NULL);
    pthread_join(pro,NULL);
    pthread_join(con,NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
