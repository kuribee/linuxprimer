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
    }else if(pid>0){
        sleep(1);
    }else{
        char* environArr[]{const_cast<char*>("A=1"),const_cast<char*>("B=2"),NULL};
        if(execle("./env","env",NULL, environArr)==-1)//历史遗留问题，参数问题
        {
            perror("execl func error");
        }
    }
    return 0;
}