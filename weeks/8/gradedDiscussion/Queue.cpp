#include "Queue.h"

template <class QueueType>
bool Queue<QueueType>::enqueue(QueueType newEntry, int max)
{
    if (this->isEmpty())
    {
        this->entries[(front % max)] = newEntry;
        back++;
        count++;
        return true;
    }
    else if (!this->isEmpty() && !this->entries[(back % max)])
    {
        this->entries[(back % max)] = newEntry;
        back++;
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

template <class QueueType>
bool Queue<QueueType>::dequeue(int max)
{
    if (this->isEmpty())
    {
        return false;
    }
    else if (!this->isEmpty() && this->entries[(front % max)])
    {
        entries[(front % max)] = '\0';
        front++;
        count--;
        return true;
    }
    return true;
}

template <class QueueType>
QueueType Queue<QueueType>::peek(int max)
{
    return entries[(front % max)];
}

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

template class Queue<char>;