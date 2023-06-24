#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

int main()
{
    int fd=open("num.txt",O_WRONLY|O_CREAT|O_APPEND,0644);
    if(fd==-1)
    {
        perror("open file error");
        return -1;
    }
    int newfd=dup(fd);
    if(newfd==-1)
    {
        perror("dup func error");
        return -1;
    }
    //std::cout<<fd<<std::endl;
    //std::cout<<newfd<<std::endl;

    const char* str="hello world";
    if(write(newfd,str,strlen(str))==-1)
    {
        perror("write func error");
        return -1;
    }

    close(fd);
    close(newfd);
    return 0;
}