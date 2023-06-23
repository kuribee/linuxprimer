#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
int main()
{
    int fd=open("num1.txt",O_WRONLY|O_CREAT|O_APPEND,0644);//0644，因为创建文件权限小，竟然无法打开看内容
    if(fd==-1)
    {
        perror("open file error");
        return -1;
    }

    const char* str ="hello world";
    int writeRet=write(fd,str,strlen(str));//不需要strlen+1
    if(writeRet==-1)
    {
        perror("write func error on line 15");
        return -1;
    }
    if(write(fd,"\n",1)==-1)
    {
        perror("write func error on line 21");
        return -1;
    }
    close(fd);
    return 0;
}