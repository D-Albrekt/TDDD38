#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template<typename T, size_t N>
class Queue
{
public:
bool empty() const;
bool full() const;
void enqueue(T value);
T& front();

private:
T queue[N]{};
int head{0};
int tail{0};
};

#include "queue.cc"


#endif