#include "BalancedTree.hpp"
#include <iostream>
using namespace std;

template<class type>
bool BalancedTree<type>::balanced(void) {
    return true;
    // if ((leftHeight - rightHeight) >= 2 || (rightHeight - leftHeight) >= 2) {
    //     return false;
    // } else {
    //     return true;
    // }
}

template<class type>
int BalancedTree<type>::getHeight(Node* item, int depth) {
    int height = 0;
    if (item == nullptr) {
        return depth;
    } else {
        std::cout << "Taking a left down! Depth: " << depth << std::endl;
        int tmp = getHeight(item->getLeft(), depth + 1);
        if (tmp > height) {
            height = tmp;
        }
        std::cout << "Taking a right down! Depth: " << depth << std::endl;
        tmp = getHeight(item->getRight(), depth + 1);
        if (tmp > height) {
            height = tmp;
        }
    }
    return height;
}

template<class type>
BalancedTree<type>::BalancedTree(void) {
    nodeCount = 0;
    root = nullptr;
}

template<class type>
bool BalancedTree<type>::isEmpty(void) {
    if (nodeCount == 0) {
        return true;
    } else {
        return false;
    }
}

template<class type>
bool BalancedTree<type>::add(Node* item) { 
    if (root == nullptr) {
        root = new Node;
        root = item;
        nodeCount++;
     } else if (balanced()) {
        // this will have cursor get to a leaf where item can be inserted
        Node* cursor;
        for (cursor = root; cursor != nullptr;) {
            if (cursor->getData().getBirthday() > item->getData().getBirthday()) {
                cout << "Cursor at: " << cursor << " is bigger than item, taking left to: " << cursor->getLeft() << endl;
                cursor = cursor->getLeft();
            } else if (cursor->getData().getBirthday() < item->getData().getBirthday()) {
                cout << "Cursor at: " << cursor << " is less than item, taking right to: " << cursor->getRight() << endl;
                cursor = cursor->getRight();
            } else {
                std::cout << "Already exists!" << std::endl;
                return false;
            }
        }
        cout << "End cursor is at: " << cursor << endl;
        cursor = item;
        nodeCount++;
    } 
    // else if (!balanced()) {}
    // if (root->getData().getBirthday() > item->getData().getBirthday()) {
    //     std::cout << "root is bigger" << std::endl;
    // } else {
    //     std::cout << "nope" << std::endl;
    // }
    return true;
}

template<class type>
bool BalancedTree<type>::remove(Node* item) {
    return true;
}

template class BalancedTree<Node>;