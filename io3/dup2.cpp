#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

int main()
{
    int fd=open("num2.txt",O_WRONLY|O_CREAT|O_APPEND,0644);
    if(fd==-1)
    {
        perror("open file error");
        return -1;
    }
    int oldfd=dup(STDOUT_FILENO);
    if(oldfd==-1)
    {
        perror("dup func error");
        return -1;
    }
    if(dup2(fd,STDOUT_FILENO)==-1)
    {
        perror("dup2 func error");
        return -1;
    }
    
    const char* str="hello world";
    if(write(STDOUT_FILENO,str,strlen(str))==-1)
    {
        perror("write func error");
        return -1;
    }
    
    if(dup2(oldfd,STDOUT_FILENO)==-1)
    {
        std::string errStr=std::string("dup2 func error, line num is : ")+std::to_string(__LINE__)+"file name is "+
        __FILE__;
        perror(errStr.c_str());
        return -1;
    }
    if(write(STDOUT_FILENO,str,strlen(str))==-1)
    {
        std::string errStr=std::string("write func error, line num is : ")+std::to_string(__LINE__)+"file name is "+
        __FILE__;
        perror(errStr.c_str());
        return -1;
    }
    close(fd);
    close(oldfd);
    return 0;
}