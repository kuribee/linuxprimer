#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

int main()
{
    struct stat st{};
    int fd=open("num.txt",O_RDWR);
    if(fd==-1)
    {
        perror("open num.txt error");
        return -1;
    }

    if(fstat(fd,&st)==-1)
    {
        perror("fstat func error");
        return -1;
    }
    char* mmapAddr=nullptr;
    if( (mmapAddr=static_cast<char*>(mmap(nullptr,st.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0))) ==MAP_FAILED)
    {
        perror("mmap func error");
        return -1;
    }

    close(fd);
    strncpy(mmapAddr,"hello world",12);
    if(munmap(mmapAddr,st.st_size)==-1)
    {
        perror("munmap func error");
        return -1;
    }
    return 0;
}