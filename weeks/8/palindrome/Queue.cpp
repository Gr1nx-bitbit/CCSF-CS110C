#include "Queue.h"

template <class QueueType>
bool Queue<QueueType>::enqueue(QueueType newEntry)
{
    if (this->isEmpty())
    {
        this->entries[front] = newEntry;
        back = (back + 1) % queueMax;
        count++;
        return true;
    }
    else if (!this->isEmpty() && !this->entries[back])
    {
        this->entries[back] = newEntry;
        back = (back + 1) % queueMax;
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

template <class QueueType>
bool Queue<QueueType>::dequeue()
{
    if (this->isEmpty())
    {
        return false;
    }
    else if (!this->isEmpty() && this->entries[front])
    {
        this->entries[front] = '\0';
        front = (front + 1) % queueMax;
        count--;
        return true;
    }
    return true;
}

template <class QueueType>
QueueType Queue<QueueType>::peek()
{
    return entries[front];
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