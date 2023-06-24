#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid=fork();
    if(pid==-1)
    {
       perror("fork func error");
       return -1; 
    }else if(pid==0){
        std::cout<<"this is child process, child process id is : "<<getpid()<<std::endl;
    }else{
        std::cout<<pid<<std::endl;
        std::cout<<"this is parent process "<<std::endl;
    }
    return 0;
}