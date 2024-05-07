#include "BalancedTree.hpp"
#include <iostream>

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
        int tmp = getHeight(item->getLeft(), depth + 1);
        if (tmp > height) {
            height = tmp;
        }
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
                cursor = cursor->getLeft();
            } else if (cursor->getData().getBirthday() < item->getData().getBirthday()) {
                cursor = cursor->getRight();
            }
        }
        cursor = new Node;
        cursor = item;
        nodeCount++;
    } 
    // else if (!balanced()) {}
    return true;
}

template<class type>
bool BalancedTree<type>::remove(Node* item) {
    return true;
}

template class BalancedTree<Node>;