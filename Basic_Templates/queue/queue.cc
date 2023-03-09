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
        queue[head] = value;
        head++;
    }
    else
    {
        //throw ...;
        
    }
}

template<typename T, size_t N>
T& Queue<T, N>::front()
{
    return queue[tail % N];
}