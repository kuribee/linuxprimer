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
        if(execlp("/bin/ls","ls","-al",NULL)==-1)//找不到，会去PATH环境变量中查找，最后找不到会报错
        {
            perror("execl func error");
        }
    }
    return 0;
}