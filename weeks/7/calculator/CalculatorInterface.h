#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H
#include "Node.h"

class CalculatorInterface 
{
    public:
        virtual bool isEmpty(void) = 0;
        virtual char peek(void) = 0;
        virtual void pop(Node<char>* ptr) = 0;
        virtual bool push(char) = 0;
};

#endif