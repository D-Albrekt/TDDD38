#include <string>
#include <vector>
#include <stdexcept> // exceptions


//My code
#include <iostream>
#include <cassert>
#include <sstream>
template<typename T>
class Formatter
{
public:
    static std::ostream& format(std::ostream& os, T const& object)
    {
        os << object;
        return os;

    }


};
template<>
class Formatter<std::string>
{
public:
    static std::ostream& format(std::ostream& os, std::string const& object)
    {
        os << '<' << object << '>';
        return os;

    }


};
template<typename T>
class Formatter<std::vector<T>>
{
public:
    static std::ostream& format(std::ostream& os, std::vector<T> const& object)
    {
        os << "{";
        for (T const& v : object)
        {
            os << ' ';
            Formatter<T>::format(os, v);
        }
        os << " }";
        return os;

    }


};


namespace preprocesser
{
    void format(std::ostream& os, std::string format_str)
    {
        if (format_str.find("{}") != std::string::npos)
        {
            throw std::runtime_error("There is too few parameters...");
        }
        else
        {
            os << format_str;
        }
    }


    template<typename First, typename... Rest>
    void format(std::ostringstream& os, std::string format_str, First const& first, Rest const&... list)
    {
        if (format_str.find("{}") == std::string::npos)
        {
            throw std::runtime_error("There is too many parameters...");
        }
        else
        {
            os << format_str.substr(0, (format_str.find("{}"))); // Add string part.
            Formatter<First>::format(os, first); //Add first parameter
            format_str.erase(0, (format_str.find("{}") + 2));  //Erase everything from 0 to }
            preprocesser::format(os, format_str, list...);
        }
    }
}

template<typename... Ts>
std::string format(std::string format_str, Ts const&... list)
    {
        std::ostringstream os{};
        preprocesser::format(os, format_str, list...);
        return os.str();
    }

//Given code again

int main()
{
    std::string str1 { format("Hello world!") };   
    assert(str1 == "Hello world!");
    
    std::string str2 { format("int: {}", 5) };
    assert(str2 == "int: 5");

    std::string my_string { "my string" };
    
    std::string str3 { format("string: {}", my_string) };
    assert(str3 == "string: <my string>");

    std::string str4 { format("{}:{}:{}", 1, 2, 3) };
    assert(str4 == "1:2:3");

    std::vector<std::string> v { "abc", "def", "ghi" };
    std::string str5 { format("vector: {}", v) };
    assert(str5 == "vector: { <abc> <def> <ghi> }");
    
    try
    {
        format("{}");
        assert(false);
    }
    catch (std::runtime_error const& e) 
    {
        std::cerr << e.what() << std::endl; 
    }

    try
    {
        format("my string", 5);
        assert(false);
    }
    catch (...) { }
}