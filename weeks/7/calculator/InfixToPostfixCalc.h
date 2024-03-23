#ifndef INFIXTOPOSTFIXCALC_H
#define INFIXTOPOSTFIXCALC_H

#include "CalculatorInterface.h"
#include "Node.h"

class InfixToPostfixCalc : public CalculatorInterface
{
    private: 
        int length;
        Node<char>* tailptr;

    public:
        InfixToPostfixCalc() { tailptr = new Node<char>; }
        InfixToPostfixCalc(char entry)
        { tailptr = new Node<char>(entry); }
        InfixToPostfixCalc(Node<char>* ptr)
        { tailptr = new Node<char>; tailptr = ptr; }
        InfixToPostfixCalc(char entry, Node<char>* ptr)
        {
            tailptr = new Node<char>(entry, ptr);
        }
        ~InfixToPostfixCalc();
        bool isEmpty(void);
        char peek(void);
        void pop(Node<char>* ptr);
        bool push(char);
        Node<char>* getTailPtr();
};

#endif