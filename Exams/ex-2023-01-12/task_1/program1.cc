#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

std::map<std::string,std::string> define_macros(std::ifstream& ifs);

std::map<std::string,std::string> define_macros(std::ifstream& ifs)
{
    std::map<std::string, std::string> macros{};
    std::string mac{};
    std::string def{};
    while (std::getline(ifs,mac, ':'))
    {
        std::getline(ifs, def);
        macros[mac] = def;
    }
    for (auto map : macros)
    {
        std::cout << "Key: " << map.first << " Val: " << map.second << '\n';
    }
    return macros;
}


int main()
{
    std::ifstream  ifs{"macros.txt"};
    if (ifs.is_open())
    define_macros(ifs);

    return 0; 
}
/*
    - Implement
        1. define_maros(std::ifstream& ifs)
            <MACRO NAME>:<Definition>
        2. string expand(string const&, MACRO_CONTAINER)


*/



/* Example output:

Note: <ENTER> and <ctrl+D> refers to user input.

$ ./a.out
I study at LiU <ENTER>
I study at Linköping University
I take COURSE at LiU <ENTER>
I take TDDD38 at Linköping University
<ctrl+D>

$ ./a.out
The course FULL_COURSE taught me how to fully utilize C++ <ENTER>
The course TDDD38 at Department of Computer and Information Science / Linköping University taught me how to fully utilize C++
<ctrl+D>

*/