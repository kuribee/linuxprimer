#include <iostream>
#include <sys/types.h>
#include <dirent.h>

unsigned blockNum=0;

void readDir(const std::string& dirName)
{
    DIR* dir=opendir(dirName.c_str());
    dirent *pDirent=nullptr;
    if(!dir)
    {
         perror("opendir error");
         return;
    }
    int oldErrorNum=errno;
    while(pDirent=readdir(dir))
    {
        const std::string& fileName=pDirent->d_name;
        if(fileName=="."||fileName=="..")
        {
            continue;
        }
        if(pDirent->d_type==DT_DIR)
        {
            for(unsigned i=0;i<blockNum;++i)
            {
                std::cout<<"\t";
            }
            std::cout<<"dir name is : "<<pDirent->d_name<<std::endl;
            const std::string childDirName=dirName+"/"+fileName;
            ++blockNum;
            readDir(childDirName);
            --blockNum;
        }
        else
        {
            for(unsigned i=0;i<blockNum;++i)
            {
                std::cout<<"  ";
            }
            std::cout<<"file name is : "<<fileName<<std::endl;
        }
    }
    if(oldErrorNum!=errno)
    {
        perror("readdir error");
         return;
    }
    closedir(dir);
}

int main()
{
    
    readDir("/home/orange/code/c++");
    return 0;
}