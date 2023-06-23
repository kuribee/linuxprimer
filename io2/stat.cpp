#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    struct stat statBuf{};
    int statRet=stat("num.txt",&statBuf);
    if(statRet==-1)
    {
        perror("stat func error");
        return -1;
    }
    std::cout<<statBuf.st_size<<std::endl;
    return 0;
}