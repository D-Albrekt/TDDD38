#include <istream>
#include <iostream>
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

struct Product
{
    string name;
    double price;
    int inventory;
};

ostream& operator<<(ostream& os, Product const& product)
{
    return os << product.name << ": "
              << product.price << " kr ("
              << product.inventory << " available)";
}

template <typename T>
T read(istream& is)
{
    T data;
    is >> data;
    return data;
}
template<>
string read<string>(istream& is)
{
    string data;
    is.ignore(numeric_limits<streamsize>::max(),'#');
    getline(is, data, '#');
    return data;

}
template<>
Product read<Product>(istream& is)
{
    Product p
    {
        read<string>(is),
        read<double>(is),
        read<int>(is)
    };
    return p;

}


template <typename T>
void write(ostream& os, T const& t)
{
    os << t << ' ';
}
template <>
void write(ostream& os, string const& t)
{
    os << '#' << t << '#';
}
template <>
void write(ostream& os, Product const& t)
{
    write(os, t.name);
    write(os, t.price);
    write(os, t.inventory);

}


int main()
{
    stringstream ss;
    { // send data to ss
        Product apple {"Red Apple", 1.5, 100};
        Product laptop{"Laptop", 5995.0, 10};
        Product monitor{"4K Monitor", 8790.0, 1};
        write(ss, apple);
        write(ss, laptop);
        write(ss, monitor);
    }
    cout << "\n\n" << ss.str() << "\n\n" << endl;


    { // recieve data from ss
        Product apple  {read<Product>(ss)};
        Product laptop {read<Product>(ss)};
        Product monitor{read<Product>(ss)};
        cout << apple << endl
             << laptop << endl
             << monitor << endl;
    }
}