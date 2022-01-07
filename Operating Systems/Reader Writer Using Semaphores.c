#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>
#include <time.h>

sem_t lock;
int hr,min,sec;

void clock_set()
{
    sec++;
    if(sec==60)
    {
        sec=0;
        min++;
    }
    if(min==60)
    {
        min=0;
        hr++;
    }
    if(hr==24)
    {
        hr=0;
    }
}

void* writer(void* _args)
{
    sem_wait(&lock);
    printf("\n\n\nTime Posted by Writer : ");
    printf("\n%02d:%02d:%02d\n",hr,min,sec);
    sem_post(&lock);
}

void* reader(void *readnum)
{
    sem_wait(&lock);
    //sleep(rand() % 3);
    sleep(1);
    printf("\nTime Read by Reader %d : ",*((int *)readnum));
    printf("\n%02d:%02d:%02d\n",hr,min,sec);
    sem_post(&lock);
}

int main()
{
    hr=23;
    min=59;
    sec=54;
    int r[3]={1,2,3},i,j;
    pthread_t write,read[3];
    sem_init(&lock,0,1);
    while(1)
    {
        clock_set();
        sleep(2);
        pthread_create(&write,NULL,writer,NULL);
        sleep(1);
        pthread_create(&read[0],NULL,reader,&r[0]);
        pthread_create(&read[1],NULL,reader,&r[1]);
        pthread_create(&read[2],NULL,reader,&r[2]);
        pthread_join(write,NULL);
        pthread_join(read[0],NULL);
        pthread_join(read[1],NULL);
        pthread_join(read[2],NULL);
    }
    sem_destroy(&lock);
    return 0;
}
