#ifndef PRINT_H
#define PRINT_H
#include <iostream>

void print()
{
        std::cout << " The end!" << std::endl; 
}

template<typename First, typename... Rest>
void print(First first,Rest... rest)
{
    std::cout << first << ' ';
    print(rest...);
}


template<typename... Ts>
void print(Ts... list)
{
    
    print(list...);
    
}


#endif