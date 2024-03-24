#ifndef QUEUE_H
#define QUEUE_H
// a queue of chars
template <class QueueType>
class Queue {
private:
   // an array to hold queue entries
   QueueType* entries;
   // properties to hold current front, 
   // back, and count
   int front;
   int back;
   int count;
   /*
   front will store the index of the front most element. so if
   we dequeue the first element front will then be incremented 
   to the index so that element becomes the beginning of the 
   queue.

   back will store the idex of the last most element. so whenever
   we enqueue a new entry back increments one. 

   we also have to make sure that front never exceeds back.

   since this is a circular array implementation, when we increment, 
   we also have to modulo the new index by the length of the array.
   */
public:
   Queue(int maxQueue) 
     { front = 0; back = 0; count = 0; entries = new QueueType[maxQueue]; }
   bool enqueue(QueueType newEntry, int max);
   bool dequeue(int max);
   QueueType peek(int max);
   bool isEmpty();
};

#endif