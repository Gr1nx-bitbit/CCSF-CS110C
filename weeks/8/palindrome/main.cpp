#include "InfixToPostfixCalc.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(Queue<char>, InfixToPostfixCalc<char>, int);

int main(void)
{
    string input = "popcorn";
    int queueMax = input.length();
    InfixToPostfixCalc<char> stack;
    Queue<char> queue(queueMax);

    for (int i = 0; i < queueMax; i++)
    {
        stack.push(input[i]);
        queue.enqueue(input[i], queueMax);
    }

    if (isPalindrome(queue, stack, queueMax))
    {
        cout << input << " is a Palindrome!" << endl;
    }
    else
    {
        cout << input << " is not a Palindrome!" << endl;
    }
    

    return 0;
}

bool isPalindrome(Queue<char> queue, InfixToPostfixCalc<char> stack, int queueMax)
{
    bool isPalindrome = false;
    for (int i = 0; i < queueMax; i++)
    {
        if (queue.peek(queueMax) == stack.peek())
        {
            queue.dequeue(queueMax);
            stack.pop(stack.getTailPtr());
            isPalindrome = true;
        }
        else
        {
            return false;
        }
    }
    return isPalindrome;
}
