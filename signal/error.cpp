#include <iostream>

int main()
{
    int *p=nullptr;//不能给nullptr赋值
    *p=1;
    return 0;
}