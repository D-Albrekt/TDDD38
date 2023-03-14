template<typename T, size_t N>
bool Queue<T,N>::empty() const
{
    return head == tail;
}

template<typename T, size_t N> 
bool Queue<T, N>::full() const
{
    return ((head % N) - N) == 0;
}

template<typename T, size_t N>
void Queue<T, N>::enqueue(T value)
{
    if(!full())
    {
        queue[head++ % N] = value;
        

    }
    else
    {
        //throw ...;
        
    }
}

template<typename T, size_t N>
T& Queue<T, N>::front() const
{
    return const_cast<T&>(queue[tail % N]);
}

template<typename T, size_t N>
T Queue<T, N>::dequeue() 
{
    if (!empty())
    {
        return queue[tail++ % N];        
    }
    else
    {
        T l{};
        return l ;
    }

}