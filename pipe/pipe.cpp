#include <iostream>
#include <unistd.h>
#include <cstring>

int main()
{
    int pipeFd[2]{};
    if(pipe(pipeFd)==-1)
    {
        perror("pipe func error");
        return -1;
    }
    pid_t pid=fork();
    if(pid==-1)
    {
        perror("fork func error");
        return -1;
    }else if (pid>0)
    {
        //sleep(1);
       close(pipeFd[0]);
       const char *str="hello world";
       if(write(pipeFd[1],str,strlen(str))==-1)
       {
            perror("write func error");
            return -1;
       }
       close(pipeFd[1]);
    }else{
        close(pipeFd[1]);
        char readBuf[32]{};
        if(read(pipeFd[0],readBuf,32)==-1)//阻塞，直到管道有数据
        {
            perror("read func error");
            return -1;
        }
        std::cout<<readBuf<<std::endl;
        close(pipeFd[0]);
    }
    return 0;
}