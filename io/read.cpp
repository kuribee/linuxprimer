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
    char buf[6]{'z','z','z','z','z','z'};
    std::cout<<buf<<std::endl;
    read(fd,buf,5);
    std::cout<<buf<<std::endl;
    read(fd,buf,3);
    std::cout<<buf<<std::endl;
    close(fd);

    return 0;
}