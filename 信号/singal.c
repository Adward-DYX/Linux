#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

static void sig_usr(int signo);


int main(void)
{
    if(signal(SIGUSR1,sig_usr)==SIG_ERR)
        perror("can`t catch SIGUSR1");
    if(signal(SIGUSR2,sig_usr)==SIG_ERR)
        perror("can`t catch SIGUSR2");
    
    for(; ;)
        pause();
}

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
        printf("received SIGUSR1\n");
    if(signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        printf("receive error");
}