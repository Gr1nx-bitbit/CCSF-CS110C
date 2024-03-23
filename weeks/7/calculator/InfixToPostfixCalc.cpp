#include "InfixToPostfixCalc.h"
#include "Node.h"

bool InfixToPostfixCalc::isEmpty(void)
{
    if (tailptr->getPrevious())
    {
        return false;
    }
    else
    {
        return true;
    }
}

char InfixToPostfixCalc::peek(void)
{
    if (tailptr)
    {
        return tailptr->getItem();
    }
    else
    {
        return '\0';
    }
}

void InfixToPostfixCalc::pop(Node<char>* ptr)
{
    if (ptr)
    {
        Node<char>* cursor = ptr;
        tailptr = ptr->getPrevious();
        delete cursor;
    }
}

bool InfixToPostfixCalc::push(char entry)
{
    Node<char>* topOfStack = new Node<char>(entry, tailptr);
    tailptr = topOfStack;
    return true;
}

InfixToPostfixCalc::~InfixToPostfixCalc()
{
    if (tailptr)
    {
        Node<char>* cursor;
        for (cursor = tailptr; cursor; delete tailptr)
        {
            tailptr = cursor;
            cursor = cursor->getPrevious();
        }
    }
    else 
    {
        delete tailptr;
    }
}

Node<char>* InfixToPostfixCalc::getTailPtr()
{
    return tailptr;
}