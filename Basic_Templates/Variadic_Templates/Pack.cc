#include <type_traits>
#include <iostream>
template <typename... Ts>
class Pack
{

};

template<typename T, typename First, typename... p>
bool contains(Pack<First, p...>)
{
    Pack<p...> p_rest;
    return std::is_same_v<T, First> || contains<T>(p_rest);


}

template<typename T>
bool contains(Pack<>) 
{
    return false;
}

template<typename T, typename... Ts>
bool contains(Pack<Ts...> list){
    return contains<T>(list);
}



template<typename T, typename first, typename... p>
int index_of(Pack<first, p...>, int index)
{
    if (std::is_same_v<T, first>)
    {
        return index;
    }
    else 
    {
        index++;
        Pack<p...> p_rest;
        return index_of<T>(p_rest, index);
    }
}

template<typename T>
int index_of(Pack<>, int index)
{
    return (index = (-1));
}

template<typename T, typename... Ts>
int index_of(Pack<Ts...> p)
{
    int index{0};
    return index_of<T>(p, index); 
}



int main()
{
    using std::cout;
    using std::endl;
    Pack<int, double, long, float, std::string> p{};

    cout << contains<long>(p) << endl;
    cout << contains<char>(p) << endl;
    cout << endl;
    cout << index_of<int>(p) << endl;
    cout << index_of<float>(p) << endl;
    cout << index_of<char>(p) << endl;


    return 0;
}