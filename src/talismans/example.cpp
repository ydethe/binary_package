// example.cpp
#include "example.h"


Example::Example()
{
    a = 0;
}

void Example::process()
{
    a += 1;
}

const int Example::getResult()
{
    return a;
}
