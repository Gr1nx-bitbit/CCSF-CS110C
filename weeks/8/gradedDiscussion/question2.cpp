#include <iostream>
#include "Queue.h"
using namespace std;

// global const for maximum queue entries
const int MAX_QUEUE = 3;

int main(void)
{
    Queue<char> cool(MAX_QUEUE);
    if (cool.isEmpty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}