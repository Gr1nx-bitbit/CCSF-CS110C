#include "Node.h"
#include <iostream>
using namespace std;

Node<int>* pop(Node<int>*&);

int main(void)
{
    Node<int>* yes = new Node<int>(5);
    cout << yes << endl << yes->getItem() << endl << yes->getPrevious() << endl << endl;
    Node<int>* no  = new Node<int>(6, yes);
    cout << no->getItem() << endl << no->getPrevious() << endl << endl;
    if (yes == no->getPrevious())
    {
        cout << "ITS WORKING!!!!!" << endl;
    }
    Node<int>* bye = pop(no);
    cout << no->getItem() << endl;

    cout << "This is my first pull request! :)" << endl; 

    return 0;
}

Node<int>* pop(Node<int>*& ptr)
{
    Node<int>* cursor = ptr;
    cout << "ADRESS: " << ptr->getPrevious() << endl;
    ptr = ptr->getPrevious();
    cout << "ADRESS: " << ptr << endl;
    cout << ptr->getItem() << endl;
    delete cursor;
    return cursor;
}