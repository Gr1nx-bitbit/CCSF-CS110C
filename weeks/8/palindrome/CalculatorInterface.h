#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H
#include "Node.h"

template<class CalcType>
class CalculatorInterface 
{
    public:
        virtual bool isEmpty(void) = 0;
        virtual CalcType peek(void) = 0;
        virtual void pop(/* Node<CalcType>* */) = 0;
        virtual bool push(CalcType) = 0;
};

#endif