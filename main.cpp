#include <iostream>
#include <string>
#include "cycle.h"

int main()
{
    Cycle c;

    for (int i = 1; i < 10; i++)
    {
        c.push_back(std::to_string(i));
        c.push_front(std::to_string(i * 10));
    }


    //for (Cycle::Iterator it = c.start(); it != c.end(); --it)
    //{
    //    std::cout << *it << " ";
    //}
}