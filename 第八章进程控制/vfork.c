#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int globvar = 6;

int main(void)
{
    int var;    /*automatic variable onthe stack*/
    pid_t pid;

    var = 88;
    printf("befor vfork\n"); /*we don`t flush stout*/

    if((pid=vfork())<0)
    {
        perror("fork error");
    }
    else if(pid==0)
    {
        globvar++;
        var++;
        _exit(0);
    }

    printf("pid = %ld,glob = %d,var = %d\n",(long)getpid(),globvar,var);
    exit(0);
}