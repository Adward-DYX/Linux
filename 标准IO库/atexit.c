#include<stdio.h>
#include<stdlib.h>

static void my_exit1(void);
static void my_exit2(void);

int main()
{
    if(atexit(my_exit2)!=0)
        perror("can`t register my_exit2");
    
    if(atexit(my_exit1)!=0)
        perror("can`t register my_exit1");
    if(atexit(my_exit1)!=0)
        perror("can`t register my_exit1");

    printf("main is done\n");
    exit(0);
}

static void my_exit1(void)
{
    printf("my_exit1\n");
}

static void my_exit2(void)
{
    printf("my_exit2\n");
}