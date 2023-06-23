#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd=open("num.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("open file error");
        return -1;
    }
    int seekRet=0;
    if((seekRet=lseek(fd,0,SEEK_END))==-1)
    {
        perror("seek func error");
        return -1;
    }

    std::cout<<"filesize "<<seekRet<<std::endl;
    close(fd);
    return 0;
}