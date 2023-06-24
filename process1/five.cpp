#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid=0;
    unsigned i=0;
    for(i=0;i<5;++i)
    {
        pid=fork();
        if(pid==-1)
        {
            perror("fork func error");
            return -1;
        }
        if(pid==0)
        {
            break;
        }
         
    }

    switch (i)
    {
    case 0:
        std::cout<<"this is first child process"<<std::endl;
        break;
    case 1:
        std::cout<<"this is second child process"<<std::endl;
        break;
    case 2:
        std::cout<<"this is third child process"<<std::endl;
        break;
    case 3:
        std::cout<<"this is forth child process"<<std::endl;
        break;
    case 4:
        std::cout<<"this is fifth child process"<<std::endl;
        break;
    case 5:
        std::cout<<"this is parent process"<<std::endl;
        break;
    default:  
        std::cout<<"unkown"<<std::endl;
        break;
    }
    
    return 0;
}