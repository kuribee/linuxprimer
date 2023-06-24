#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork func error");
        return -1;
    }else if(pid>0)
    {

       
    }else
    {
        if(setsid()==-1)
        {
            perror("setsid func error");
            return -1;
        }
        if(chdir("/tmp")==-1)
        {
            perror("chdir func error");
            return -1;
        }
        umask(0);//不需要检查返回值
        for(unsigned i=0;i<getdtablesize();++i)
        {
            close(i);
        }
        sleep(20);
    }
    return 0;
}