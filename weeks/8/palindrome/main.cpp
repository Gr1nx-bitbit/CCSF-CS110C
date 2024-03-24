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
        queue.enqueue(input[i]);
    }

    if (isPalindrome(queue, stack, queueMax))
    {
        cout << input << " is a Palindrome!" << endl;
    }
    else
    {
        cout << input << " is not a Palindrome!" << endl;
    }

    //need to do this because isPalindrome() makes a copy of queue and dequeues that instead of the 
    //original 
    for (int i = 0; i < queueMax; i++)
    {
        queue.dequeue();
    }


    input = "racecar";
    queueMax = input.length();
    for (int i = 0; i < queueMax; i++)
    {
        stack.push(input[i]);
        queue.enqueue(input[i]);
    }

    if (isPalindrome(queue, stack, queueMax))
    {
        cout << input << " is a Palindrome!" << endl;
    }
    else
    {
        cout << input << " is not a Palindrome!" << endl;
    }

    //tailptr gets freed twice
    cout << stack.getTailPtr() << endl;

    return 0;
}

//this function screws up how if we can reinput charcters into queue because it makes a copy of it
//at least i think that's whats wrong here. 
//yeah it seems like that's the problem, so i have to deqeue the queue outside the function again :(
bool isPalindrome(Queue<char> queue, InfixToPostfixCalc<char> stack, int queueMax)
{
    bool isPalindrome = false;
    for (int i = 0; i < queueMax; i++)
    {
        if (queue.peek() == stack.peek())
        {
            queue.dequeue();
            stack.pop();
            isPalindrome = true;
        }
        else
        {
            return false;
        }
    }
    return isPalindrome;
}
