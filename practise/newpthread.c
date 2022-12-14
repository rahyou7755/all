#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<pthread.h>
void *fun()
{
printf("Hello\nWe are learning threads concept\n");
sleep(30);
}
int main()
{
pthread_t t_id;
int ret;
printf("Process Id :%d \n",getpid());
ret = pthread_create(&t_id,NULL,fun,NULL);
if (ret == 0)
{
printf("Successfully created\n");
}
else
{
printf("NOT created\n");
}
pthread_join(t_id,NULL);
printf("Thread teminated\n");
}
