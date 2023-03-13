#include <utility>
#include <string>

template<typename T>
int count();

template<typename T>
class Tracker : public T
{
public:
template<typename... ARG>
Tracker(ARG&&... list) : T(std::forward<ARG>(list)...)
{
    counter++;
}

~Tracker()
{
    counter--;
}

Tracker(Tracker<T> const& other) : Tracker<T>(other)
{
    counter++;
}

Tracker(Tracker<T> &&) = default;

Tracker<T>& operator=(Tracker<T> const& other)
{
    Tracker<T> tmp{other};
    *this  = std::move(tmp);
    return *this;
}

private:
static int counter;
friend int count<T>();

};


template <typename T>
int Tracker<T>::counter{0};


template<typename T>
int count()
{
    return Tracker<T>::counter;
}