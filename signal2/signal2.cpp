#include <iostream>
#include <unistd.h>
#include <signal.h>

void signal_handler_func(int signalNum)
{
    std::cout<<"catch SIGINT signal"<<std::endl;
}
int main()
{
    if(signal(SIGINT,signal_handler_func)==SIG_ERR)
    {
        perror("signal func error");
        return -1;
    }
    while(1)
    {
        std::cout<<"hello world"<<std::endl;
        sleep(1);
    }
    return 0;
}