#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork func error");
        return -1;
    }else if (pid>0)
    {
        if(mkfifo("tmp",0644)==-1)
        {
            perror("mkfifo func error");
            return -1;
        }
        int inFifoFd=open("tmp",O_WRONLY);
        if(inFifoFd==-1)
        {
            perror("open inFifoFd error");
            return -1;
        }
        const char* str="hello world";
        if(write(inFifoFd,str,strlen(str))==-1)
        {
            perror("write func error");
            return -1;
        }
        close(inFifoFd);
    }else{
        sleep(1);
        int outFifoFd=open("tmp",O_RDONLY);
        if(outFifoFd==-1)
        {
            perror("open outFifoFd error");
            return -1;
        }
        char readBuf[32]{};
        if(read(outFifoFd,readBuf,32)==-1)
        {
            perror("read func error");
            return -1;
        }
        std::cout<<readBuf<<std::endl;
        close(outFifoFd);
        if(unlink("tmp")==-1)
        {
            perror("unlink func error");
            return -1;
        }
    }
    return 0;
}