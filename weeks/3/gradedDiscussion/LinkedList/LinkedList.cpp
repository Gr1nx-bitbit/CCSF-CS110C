//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
   headPtr = nullptr;
   itemCount = 0;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());

      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
void LinkedList<ItemType>::print(int position)
{
  cout << "Previous pointer points to: " << getNodeAt(position - 1)->getItem() << endl;
  cout << "Next pointer points to: " << getNodeAt(position)->getItem() << endl;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      // This implementation ignores newPosition, and always put the new
      // item at the beginning of the list.
      // Your assignment is to correctly insert the item into newPosition
      if (isEmpty())
      {
        headPtr = newNodePtr;
        newNodePtr->setNext(nullptr);
        newNodePtr->setPrev(nullptr);
        tailPtr = newNodePtr;
      }
      else if (newPosition == 1)
      {
        headPtr->setPrev(newNodePtr);
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
      }
      else if (newPosition == (itemCount + 1))
      {
        tailPtr->setNext(newNodePtr);
        newNodePtr->setPrev(tailPtr);
        tailPtr = newNodePtr;
      }
      else
      {
        Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
        newNodePtr->setNext(prevPtr->getNext());
        newNodePtr->setPrev(prevPtr);
        prevPtr->setNext(newNodePtr);
      }

      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         Node<ItemType>* nextPtr; //To hold node after the one being deleted

         // Point to node to delete
         curPtr = prevPtr->getNext();
         nextPtr = curPtr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(nextPtr);
         nextPtr->setPrev(prevPtr);
      }  // end if

      // Return node to system
      curPtr->setNext(nullptr);
      curPtr->setPrev(nullptr);
      delete curPtr;
      curPtr = nullptr;

      itemCount--;  // Decrease count of entries
   }  // end if

   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end getEntry

template<class ItemType>
bool LinkedList<ItemType>::reverse(Node<ItemType>* cursor)
{
  if (isEmpty())
  {
    return false;
  }
  int pos = 1;
  for (cursor = headPtr; cursor->getNext() != nullptr; cursor = cursor->getPrev())
  {
    Node<ItemType>* tmp = cursor->getNext();
    cursor->setNext(cursor->getPrev());
    cursor->setPrev(tmp);
    cout << "At position " << pos << " with value: " << cursor->getItem() << endl;
    pos++;
  } // this only works up until the second to last node so we have to change tailPtr seperately
  // (cursor will also be equal to the second to last node at this point)
  Node<ItemType>* tmp = tailPtr->getNext();
  tailPtr->setNext(tailPtr->getPrev());
  tailPtr->setPrev(tmp);
  tmp = headPtr;
  headPtr = tailPtr;
  tailPtr = tmp;
  cursor = nullptr;

  return true;

}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );

   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}  // end getNodeAt



// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;
