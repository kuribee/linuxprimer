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

        char * paramArr[]{const_cast<char*>("ls"),const_cast<char*>("-al"),NULL};//char * 指向const char *
        if(execvp("ls",paramArr)==-1)//找不到，会去PATH环境变量中查找，最后找不到会报错
        {
            perror("execl func error");
        }
    }
    return 0;
}