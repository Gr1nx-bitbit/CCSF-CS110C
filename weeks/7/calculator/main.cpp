#include "InfixToPostfixCalc.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

string parse(string, int);
bool opPrecedence(char, char);

int main(void)
{
    string input = "2+(3-4)/4+2";
    string hey = parse(input, input.length());
    cout << hey << endl;

    return 0;
}

string parse(string input, int size)
{
    string ok = "";
    InfixToPostfixCalc stack;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        //cout << input[i] << " :: " << stack.peek() << endl;
        if (input[i] > 47 && input[i] < 58)
        {
            ok += input[i];
            index++;
        }
        else
        {
            //cout << stack.peek() << endl;
            if (input[i] == ')')
            {
                while (stack.peek() != '(')
                {
                    //cout << stack.peek() << endl;
                    //cout << "." << endl;
                    ok += stack.peek();
                    stack.pop(stack.getTailPtr());
                    
                }
                //get rif of '('
                stack.pop(stack.getTailPtr());
            }
            else if (input[i] == '\0')
            {
                while (stack.getTailPtr())
                {
                    ok += stack.peek();
                    stack.pop(stack.getTailPtr());
                }
            }
            else
            {
                stack.push(input[i]);
            }
            // else if (input[i] == '(')
            // {
            //     stack.push(input[i]);
            // }
            // else
            // {
            //     if (stack.isEmpty())
            //     {
            //         stack.push(input[i]);
            //     }
            //     else
            //     {
            //         bool cycle = false;
            //         while(stack.peek() != '(')
            //         {
            //             if (opPrecedence(stack.peek(), input[i]))
            //             {
            //                 ok += stack.peek();
            //                 stack.pop(stack.getTailPtr());
            //                 cycle = true;
            //             }
            //             else if (!opPrecedence(stack.peek(), input[i]) || stack.isEmpty())
            //             {
            //                 stack.push(input[i]);
            //                 cycle = true;
            //             }
            //         }

            //         //if the first operator is a '(' then the new op never gets
            //         //pushed onto the stack or appended to the string
            //         if (!cycle)
            //         {
            //             stack.push(input[i]);
            //         }
            //     }
            // }
        }
    }
    while (stack.getTailPtr())
    {
        ok += stack.peek();
        stack.pop(stack.getTailPtr());
    }
    return ok;
}

//returns true if op1 is of greater or equal precedence
//and returns false is op1 is of lesser precedence
//assumes the operators are either '/, *, +, -'
//and that a prelimenary check of whether the bf 
//operator is '('
bool opPrecedence(char bf, char after)
{
    if (bf == '*' || bf == '/')
    {
        return true;
    }
    else if (bf == '+' || bf == '-')
    {
        if (after == '*' || after == '/')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}