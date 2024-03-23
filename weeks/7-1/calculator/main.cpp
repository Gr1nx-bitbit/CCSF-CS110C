#include "InfixToPostfixCalc.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main(void)
{
    InfixToPostfixCalc<char> cool;
    for (int i = 0; i < 4; i++)
    {
        cool.push((i*i) + '0');
        cout << cool.peek() << endl;
    }
    cout << endl << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << cool.peek() << endl; 
        //Node<char>* ref = cool.getTailPtr();
        cool.pop(cool.getTailPtr());
    }

    return 0;
}
