#include <iostream>
#include <unistd.h>

int main()
{
    while(1)
    {
        sleep(1);
        std::cout<<"hello world"<<std::endl;
    }
    return 0;
}