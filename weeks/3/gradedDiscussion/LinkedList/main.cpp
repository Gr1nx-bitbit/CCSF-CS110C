//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	cout << "The list contains " << endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl << endl;
}  // end displayList

void listTester()
{
	ListInterface<string>* listPtr = new LinkedList<string>();
	cout << "Testing the Link-Based List:" << endl;
	string data[] = {"one", "two", "three", "four", "five", "six"};
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
	for (int i = 0; i < 6; i++)
   {
		if (listPtr->insert(i + 1, data[i]))
         cout << "Inserted " << listPtr->getEntry(i + 1)
         << " at position " << (i + 1) << endl;
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1)
         << endl;
	}  // end for

   displayList(listPtr);

   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;

   cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
   cout << "After replacing the entry at position 3 with XXX: ";
   listPtr->setEntry(3, "XXX");
   displayList(listPtr);

} // end listTester



int main()
{
   listTester();
	 LinkedList<int>* listPtr = new LinkedList<int>();
	 for (int i = 0; i < 4; i++)
	 {
		 listPtr->insert(i + 1, i*i*i);
	 }

	 Node<int>* passIn;
	 if (listPtr->reverse(passIn))
	 {

		 //listPtr->remove(3);
		 for (int i = 0; i < listPtr->getLength(); i++)
		 	cout << listPtr->getEntry(i + 1);
		 cout << endl;
		 listPtr->insert(2, 5);
		 listPtr->insert(4, 9);
		 listPtr->reverse(passIn);
		 //for (int i = 0; i < listPtr->getLength(); i++)
		 cout << listPtr->getEntry(1);
		 cout << listPtr->getEntry(2);
		 cout << listPtr->getEntry(3);
		 cout << listPtr->getEntry(4);
		 //cout << listPtr->getEntry(5);
		 cout << endl;
		 /*
		 listPtr->reverse(passIn);
		 cout << "Length: " << listPtr->getLength() << endl;
		 //cout << listPtr->getEntry(3) << endl;

		 for (int i = 0; i < listPtr->getLength(); i++)
		 	{
				cout << i << endl;
		 		cout << listPtr->getEntry(i + 1) << endl;
				cout << endl;
		  }
			*/
	 }
   return 0;
}  // end main

/***** EXPECTED OUTPUT WITH CORRECT INSERT FUNCTION
Testing the Link-Based List:
isEmpty: returns 1; should be 1 (true)
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
The list contains
one two three four five six

isEmpty: returns 0; should be 0 (false)
getLength returns : 6; should be 6
The entry at position 4 is four; should be four
After replacing the entry at position 3 with XXX: The list contains
one two XXX four five six */
