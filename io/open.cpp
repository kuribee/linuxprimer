#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd=open("num.txt",O_RDONLY);
    if(fd==-1)//对于系统调用，失败返回-1
    {
        perror("open file error");
        return -1;
    }
    std::cout<<fd<<std::endl;//3,因为0,1,2已被占用

    int readNum=0;
    char readBuf[8]{};

    while(readNum=read(fd,readBuf,8))
    {
        if(readNum==-1)
        {
            perror("read func error");
            return -1;
        }
        std::cout<<"readNUM"<<readNum<<std::endl;
        std::cout<<readBuf<<std::flush;
    }
    std::cout<<std::endl;
    close(fd);//调用不会失败，所以不关注返回值；必须close,否则只有进程结束时，系统才会销毁掉
    return 0;
}