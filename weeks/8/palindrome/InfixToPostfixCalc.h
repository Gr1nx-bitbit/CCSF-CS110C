#ifndef INFIXTOPOSTFIXCALC_H
#define INFIXTOPOSTFIXCALC_H

#include "CalculatorInterface.h"
#include "Node.h"

template<class CalcType>
class InfixToPostfixCalc : public CalculatorInterface<CalcType>
{
    private: 
        int length;
        Node<CalcType>* tailptr;

    public:
        InfixToPostfixCalc() { tailptr = new Node<CalcType>; }
        InfixToPostfixCalc(CalcType entry)
        { tailptr = new Node<CalcType>(entry); }
        InfixToPostfixCalc(Node<CalcType>* ptr)
        { tailptr = new Node<CalcType>; tailptr = ptr; }
        InfixToPostfixCalc(CalcType entry, Node<CalcType>* ptr)
        {
            tailptr = new Node<CalcType>(entry, ptr);
        }
        ~InfixToPostfixCalc();
        bool isEmpty(void);
        CalcType peek(void);
        void pop(/* Node<CalcType>* ptr */);
        bool push(CalcType);
        Node<CalcType>* getTailPtr();
};

#endif