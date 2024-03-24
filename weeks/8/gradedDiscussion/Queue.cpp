#include "Queue.h"

template <class QueueType>
bool Queue<QueueType>::enqueue(QueueType newEntry)
{}

template <class QueueType>
bool Queue<QueueType>::dequeue()
{}

template <class QueueType>
char Queue<QueueType>::peek()
{}

template <class QueueType>
bool Queue<QueueType>::isEmpty()
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}