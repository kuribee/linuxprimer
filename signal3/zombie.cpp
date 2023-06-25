#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
//not good
void SIGCHILD_handler_func(int sigChild)
{
    if(wait(nullptr)==-1)
    {
        perror("wait func error");
        exit(1);
    }
}

int main()
{
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork func error");
        return -1;
    }else if(pid>0)
    {
        signal(SIGCHLD,SIGCHILD_handler_func);
        while(1)
        {
            sleep(1);
            std::cout<<"hello world"<<std::endl;
        }
    }else
    {

    }
}