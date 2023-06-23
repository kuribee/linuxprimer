#include <iostream>
#include <sys/types.h>
#include <dirent.h>



int main()
{
    
    DIR* dir=opendir("./");
    dirent *pDirent=nullptr;
    if(!dir)
    {
         perror("opendir error");
         return -1;
    }
    int oldErrorNum=errno;
    while(pDirent=readdir(dir))
    {
        std::cout<<pDirent->d_name<<std::endl;
    }
    if(oldErrorNum!=errno)
    {
        perror("readdir error");
         return -1;
    }
    closedir(dir);
    return 0;
}