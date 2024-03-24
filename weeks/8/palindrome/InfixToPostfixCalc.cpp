#include "InfixToPostfixCalc.h"
#include "Node.h"

template<class CalcType>
bool InfixToPostfixCalc<CalcType>::isEmpty(void)
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

template<class CalcType>
CalcType InfixToPostfixCalc<CalcType>::peek(void)
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

template<class CalcType>
void InfixToPostfixCalc<CalcType>::pop(Node<CalcType>* ptr)
{
    if (ptr)
    {
        Node<CalcType>* cursor = ptr;
        tailptr = ptr->getPrevious();
        delete cursor;
    }
}

template<class CalcType>
bool InfixToPostfixCalc<CalcType>::push(CalcType entry)
{
    Node<CalcType>* topOfStack = new Node<CalcType>(entry, tailptr);
    tailptr = topOfStack;
    return true;
}

template<class CalcType>
InfixToPostfixCalc<CalcType>::~InfixToPostfixCalc()
{
    if (tailptr)
    {
        Node<CalcType>* cursor;
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

template<class CalcType>
Node<CalcType>* InfixToPostfixCalc<CalcType>::getTailPtr()
{
    return tailptr;
}

template class InfixToPostfixCalc<char>;