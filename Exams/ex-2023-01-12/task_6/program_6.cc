#include <cassert>
#include <vector>
#include <list>
#include <deque>

#include <iostream>


namespace help
{
    template<typename T>
    std::vector<T> flatten(T const& t)
    {
        return std::vector<T>{t};
    }
    template<typename T, typename Container>
    auto flatten(Container container) -> decltype(std::begin(container), std::vector<T>{})
    {
        std::vector<T> vec{};
        for (auto e : container)
        {   
            std::vector<T> temp(help::flatten<T>(e));
            vec.insert(std::end(vec), std::begin(temp), std::end(temp));
        }
        return vec;
    }
/*
    template<typename T, typename U>
    std::vector<T> flatten(T const& inner)
    {
        vector
        for (auto e : inner)
        {

        }
        return ;
    }
*/
}






template<typename T,typename Container>
std::vector<T> flatten(Container const& container)
{
    return help::flatten<T>(container);

}





//SFINAE?
//decltype?
//Order of specialization?
//Comma operator?

int main()
{
    {
        assert( flatten<int>(5) == std::vector<int> { 5 } );
    }
   {
        std::vector<std::list<int>> v {
            { 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9 }
        };

        std::vector<int> expected { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        assert( flatten<int>(v) == expected );
    }
    
/*
    {
        std::vector<char> data {
            'a', 'b', 'c'
        };

        using iterator = std::vector<char>::iterator;
        
        std::vector<std::vector<iterator>> v {
            { std::begin(data), std::begin(data), std::begin(data) },
            { std::begin(data) + 1 },
            { std::begin(data) + 2, std::begin(data) + 2 }
        };
        
        std::vector<char> expected { 'a', 'a', 'a', 'b', 'c', 'c' };
        assert( flatten<char>(v) == expected );
    }

    {
        std::vector<std::list<std::deque<std::vector<float>>>> v
        {
            {
                {
                    { 1.2, 3.45, 6.0 },
                    { 7.8, 9.10 },
                    
                },
                {
                    { 11.1213, 14.0 },
                    { 15.16, 17.18, 19.20 },
                    { 21.22 }
                },
            },
            
            {
                {},
                {
                    { },
                    { 23.2425 },
                    { }
                },
                {}
            },
        };

        std::vector<float> expected { 1.2, 3.45, 6.0, 7.8, 9.10, 11.1213, 14.0,
                                      15.16, 17.18, 19.20, 21.22, 23.2425 };
        assert( flatten<float>(v) == expected );
    }

    {

        int x { 5 };
        std::vector<int*> v { &x };

        assert(( flatten<int>(v) == std::vector<int>{ 5 } ));
        assert(( flatten<int*>(v) == std::vector<int*>{ &x } ));
    }

    */
}