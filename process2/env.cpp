#include <iostream>
#include <unistd.h>

extern char ** environ;
//char* argv[]

int main()
{
    for(char** ptr=environ;*ptr!=nullptr;++ptr)
    {
        std::cout<<*ptr<<std::endl;
    }
    return 0;
}