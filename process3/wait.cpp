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

        
        if(wait(nullptr)==-1)
        {
            perror("wait func error");
            return -1;
        }
        sleep(15);
    }else
    {
 
    }
    return 0;
}