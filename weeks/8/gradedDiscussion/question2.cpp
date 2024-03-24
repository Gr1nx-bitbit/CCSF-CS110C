#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

void isEmpty(Queue<char> cool)
{
    if (cool.isEmpty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

// global const for maximum queue entries
const int MAX_QUEUE = 3;

int main(void)
{
    Queue<char> cool(MAX_QUEUE);
    isEmpty(cool);
    string yes = "rise, children of the ashes!";
    for (int i = 0; i < (MAX_QUEUE + 1); i++)
    {
        cool.enqueue(yes[i], MAX_QUEUE);
    }
    for (int i = 0; i < (MAX_QUEUE + 1); i++)
    {
        cout << cool.dequeue(MAX_QUEUE) << endl;
    }
    isEmpty(cool);
    cool.enqueue(yes[2], MAX_QUEUE);
    cout << cool.peek(MAX_QUEUE) << endl;
    return 0;
}