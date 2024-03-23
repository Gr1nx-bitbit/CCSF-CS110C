#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template<class QueueType>
class QueueInterface
{
    public:
        //checks if the queue is empty
        virtual bool isEmpty() = 0;
        //adds an entry to the back of the queue
        virtual bool enQueue(const QueueType& entry) = 0;
        //removes an entry from the front of the queue
        virtual bool deQueue() = 0;
        //gets the entry at the front of the queue
        virtual QueueType peekFront() = 0;
};

#endif