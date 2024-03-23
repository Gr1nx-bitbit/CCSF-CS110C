#include "InfixToPostfixCalc.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

struct ReturnType
{
    int size;
    int* ref;
};

string parse(string, int);

int main(void)
{
    string input = "2+(3-4)/4+2";
    string hey = parse(input, input.length());
    cout << hey << endl;
    // for (int i = 0; i < hey.length(); i++)
    // {
    //     cout << hey.ref[i] << endl;
    // }

    // InfixToPostfixCalc cool;
    // for (int i = 0; i < 4; i++)
    // {
    //     cool.push((i*i) + '0');
    //     cout << cool.peek() << endl;
    // }
    // cout << endl << endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << cool.peek() << endl; 
    //     //Node<char>* ref = cool.getTailPtr();
    //     cool.pop(cool.getTailPtr());
    // }

    return 0;
}

string parse(string input, int size)
{
    string ok = "";
    InfixToPostfixCalc stack;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] > 47 && input[i] < 58)
        {
            ok += input[i];
            index++;
        }
        else
        {
            if (input[i] == ')')
            {
                while (stack.peek() != '(')
                {
                    cout << "fortissimo" << endl;
                    ok += stack.peek();
                    stack.pop(stack.getTailPtr());
                }
                //get rif of '('
                stack.pop(stack.getTailPtr());
            }
            else if (input[i] == '\0')
            {
                cout << "cool" << endl;
                while (stack.getTailPtr())
                {
                    cout << "hey" << endl;
                    ok += stack.peek();
                    stack.pop(stack.getTailPtr());
                }
            }
            else
            {
                cout << "yolo" << endl;
                if (stack.isEmpty())
                {
                    stack.push(input[i]);
                }
                else
                {
                    if (input[i] == '+' || input[i] == '-')
                    {
                        while((stack.peek() != '+' || stack.peek() != '-') && !stack.isEmpty())
                        {
                            cout << "hey0" << endl;
                            if (stack.peek() == '(')
                            {
                                cout << "hey00" << endl;
                                stack.pop(stack.getTailPtr());
                                break;
                            }
                            else
                            {
                                cout << "hey01" << endl;
                                ok += stack.peek();
                                stack.pop(stack.getTailPtr());
                            }
                            
                        }
                    }
                    else
                    {
                        while((stack.peek() == '*' || stack.peek() == '/' || stack.peek() == '(') && !stack.isEmpty())
                        {
                            cout << "hey1" << endl;
                            if (stack.peek() == '(')
                            {
                                stack.pop(stack.getTailPtr());
                                break;
                            }
                            else
                            {
                                ok += stack.peek();
                                stack.pop(stack.getTailPtr());
                            }
                        }
                    }
                }
                
            }
        }
    }
    while (stack.getTailPtr())
    {
        ok += stack.peek();
        stack.pop(stack.getTailPtr());
    }
    cout << "HEYYY" << endl;
    return ok;
}

//3-4
//4+2
//-1/6
//2-1/6