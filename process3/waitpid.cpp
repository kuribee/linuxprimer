#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork func error");
        return -1;
    }else if(pid>0)
    {
        //第三个参数0表示阻塞,WNOHANG表示不阻塞
        //-1表示任何子进程
        if(waitpid(-1,nullptr,0)==-1)
        {
            perror("waitpid func error");
            return -1;
        }
        sleep(15);
    }else
    {
 
    }
    return 0;
}