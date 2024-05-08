#include "BalancedTree.hpp"
#include <iostream>
using namespace std;

//#define DEBUG

template<class type>
bool BalancedTree<type>::balanced(void) {
    return true;
    // if ((getHeight(root->getLeft(), 1) - getHeight(root->getRight(), 1)) >= 2 || (getHeight(root->getRight(), 1) - getHeight(root->getLeft(), 1)) >= 2) {
    //     return false;
    // } else {
    //     return true;
    // }
}

template<class type>
int BalancedTree<type>::getHeight(Node* item, int depth) {
    int height = 0;
    if (item == nullptr) {
        return depth - 1;
    } else {
        #ifdef DEBUG
        cout << "Parent is: " << item->getParent() << " Item is: " << item->getData().getBirthday().day
        << " Taking a left down to: " << item->getLeft() << " Depth: " << depth << endl << endl;
        #endif
        int tmp = getHeight(item->getLeft(), depth + 1);
        if (tmp > height) {
            height = tmp;
        }
        #ifdef DEBUG
        cout << "Parent is: " << item->getParent() << " Item is: " << item->getData().getBirthday().day
        << " Taking a right down to: " << item->getRight() << " Depth: " << depth << endl << endl;
        #endif
        tmp = getHeight(item->getRight(), depth + 1);
        if (tmp > height) {
            height = tmp;
        }
    }
    return height;
}

template<class type>
Node* BalancedTree<type>::getNodeatHeight(Node* requested, int requestedDepth, int currentDepth) {
    if (currentDepth == requestedDepth) {
        return requested;
    } else {
        #ifdef DEBUG1
        cout << "Parent is: " << requested->getParent() << " Item is: " << requested->getData().getBirthday().day
        << " Taking a left down to: " << requested->getLeft() << " Depth: " << currentDepth << endl;
        #endif

        if (requested->getLeft() != nullptr)
            requested = getNodeatHeight(requested->getLeft(), requestedDepth, currentDepth + 1);
        
        #ifdef DEBUG1
        cout << "Parent is: " << requested->getParent() << " Item is: " << requested->getData().getBirthday().day
        << " Taking a right down to: " << requested->getRight() << " Depth: " << currentDepth << endl << endl;
        #endif
        if (requested->getRight() != nullptr)
            requested = getNodeatHeight(requested->getRight(), requestedDepth, currentDepth + 1);
    }
    return requested;
}

template<class type>
void BalancedTree<type>::swap(Node* source, Node* destination) {
    Node* sourceParent = source->getParent();
    bool ParentLeft = false;
    bool ParentRight = false;
    Node* sourceLeft = source->getLeft();
    Node* sourceRight = source->getRight();
    Node* destLeft = destination->getLeft();
    Node* destRight = destination->getRight();

    if (source->getParent() != nullptr) {
        if (source->getParent()->getLeft() == source) {
            ParentLeft = true;
        } else if (source->getParent()->getRight() == source) {
            ParentRight = true;
        }
    }

    #ifdef DEBUG
    cout << "Source Parent: " << source->getParent() << endl;
    cout << "Source: " << source << endl;
    cout << "Source Left: " << source->getLeft() << endl;
    cout << "Source Right: " << source->getRight() << endl;
    cout << "Destination Parent: " << destination->getParent() << endl;
    cout << "Destination: " << destination << endl;
    cout << "Destination Left: " << destination->getLeft() << endl;
    cout << "Destination Right: " << destination->getRight() << endl << endl;
    #endif

    //point source children to destination children
    #ifdef DEBUG
    cout << "Setting source left to destination left: " << destLeft << endl; 
    cout << "Setting source right to destination right: " << destRight << endl << endl;
    #endif
    source->setLeft(destLeft);
    source->setRight(destRight);
    #ifdef DEBUG
    cout << "New source left: " << source->getLeft() << endl;
    cout << "New source right: " << source->getRight() << endl << endl;
    #endif

    //point destination to source and it's children
    if (sourceLeft == destination) {
        #ifdef DEBUG
        cout << "Destination is left of source. Setting destination left to source." << endl;
        cout << "Setting destination right to source right: " << sourceRight << endl;
        #endif
        destination->setLeft(source);
        destination->setRight(sourceRight);
        #ifdef DEBUG
        cout << "Destination left: " << destination->getLeft() << endl;
        cout << "Destination right: " << destination->getRight() << endl << endl;
        #endif
    } else if (sourceRight == destination) {
        #ifdef DEBUG
        cout << "Destination is right of source. Setting destination right to source." << endl;
        cout << "Setting destination left to source left: " << sourceLeft << endl;
        #endif
        destination->setRight(source);
        destination->setLeft(sourceLeft);
        #ifdef DEBUG
        cout << "Destination left: " << destination->getLeft() << endl;
        cout << "Destination right: " << destination->getRight() << endl << endl;
        #endif
    }

    //point destination to souce parent and then make destination source's parent
    #ifdef DEBUG
    cout << "Setting destination parent to source parent: " << sourceParent << endl;
    cout << "Setting source parent to destination" << endl;
    #endif
    destination->setParent(sourceParent);
    source->setParent(destination);
    if (destination->getParent() == nullptr) {
        #ifdef DEBUG 
        cout << "Source parent is null so destination is new root" << endl; 
        #endif
        root = destination;
    } else {
        //need to set parents child to new destination so it stays attached
        if (ParentLeft) {
            destination->getParent()->setLeft(destination);
        } else if (ParentRight) {
            destination->getParent()->setRight(destination);
        }
    }
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
        for (cursor = root; true;) {
            if (cursor->getData().getBirthday() > item->getData().getBirthday()) {
                if (cursor->getLeft() == nullptr) {
                    cursor->setLeft(item);
                    item->setParent(cursor);
                    break;
                } else {
                    cursor = cursor->getLeft();
                }
            } else if (cursor->getData().getBirthday() < item->getData().getBirthday()) {
                if (cursor->getRight() == nullptr) {
                    cursor->setRight(item);
                    item->setParent(cursor);
                    break;
                } else {
                    cursor = cursor->getRight();
                }
            } else {
                std::cout << "Already exists!" << std::endl;
                cout << "Cursor: " << cursor->getData().getBirthday().month << "-" << cursor->getData().getBirthday().day << 
                " Item: " << item->getData().getBirthday().month << "-" << item->getData().getBirthday().day << endl << endl;
                return false;
            }
        }
        nodeCount++;
    } else if (!balanced()) {
        int leftHeight = getHeight(root->getLeft(), 1);
        int rightHeight = getHeight(root->getRight(), 1);
        int average = ((leftHeight + rightHeight) / 2) - 1;
        Node* newRoot;
        if (rightHeight > leftHeight) {
            newRoot = getNodeatHeight(root->getRight(), average, 1);
        } else {
            newRoot = getNodeatHeight(root->getLeft(), average, 1);
        }

        cout << "New Root: " << newRoot->getData().getBirthday().month << "-" << newRoot->getData().getBirthday().day << endl << endl;

        //this will get us a new balanced tree. Then we have to actually add the new node.
        if (newRoot->getData().getBirthday() < root->getData().getBirthday()) {
            //go down right children to see where old root can fit
            cout << "new root is smaller!" << endl;

            if (newRoot->getRight() == nullptr) {
                newRoot->setRight(root);
                root->setParent(newRoot);
                root = newRoot;
            }
            for (Node* cursor = newRoot->getRight(); true;) {
                #ifndef DEBUG
                cout << "Cursor at: " << cursor << " with value: " << cursor->getData().getBirthday().month << "-" << cursor->getData().getBirthday().day << endl;
                cout << "Old root at: " << root << " with value: " << root->getData().getBirthday().month << "-" << root->getData().getBirthday().day << endl;
                #endif
                if (cursor->getData().getBirthday() < root->getData().getBirthday()) {
                    if (cursor->getRight() == nullptr) {
                        cursor->setRight(root);
                        root->setParent(cursor);
                        root = newRoot; 
                        break;
                    } else {
                        cursor = cursor->getRight();
                    }
                } else if (cursor->getData().getBirthday() > root->getData().getBirthday()) {
                    if (cursor->getLeft() == nullptr) {
                        cursor->setLeft(root);
                        root->setParent(cursor);
                        root = newRoot;
                        break;
                    } else {
                        cursor = cursor->getLeft();
                    }
                }
            }
        } else {
            //go down left children to see where old root can fit
            cout << "new root is bigger!" << endl;
        
            if (newRoot->getLeft() == nullptr) {
                newRoot->setLeft(root);
                root->setParent(newRoot);
                root = newRoot;
            } else {
                for (Node* cursor = newRoot->getLeft(); true;) {
                    #ifndef DEBUG
                    cout << "Cursor at: " << cursor << " with value: " << cursor->getData().getBirthday().month << "-" << cursor->getData().getBirthday().day << endl;
                    cout << "Old root at: " << root << " with value: " << root->getData().getBirthday().month << "-" << root->getData().getBirthday().day << endl;
                    #endif
                    if (cursor->getData().getBirthday() < root->getData().getBirthday()) {
                        if (cursor->getRight() == nullptr) {
                            cursor->setRight(root);
                            root->setParent(cursor);
                            root = newRoot; 
                            break;
                        } else {
                            cursor = cursor->getRight();
                        }
                    } else if (cursor->getData().getBirthday() > root->getData().getBirthday()) {
                        if (cursor->getLeft() == nullptr) {
                            cursor->setLeft(root);
                            root->setParent(cursor);
                            root = newRoot;
                            break;
                        } else {
                            cursor = cursor->getLeft();
                        }
                    }
                }
            }
        }

        // cout << "0" << endl;
        // cout << "Going to add: " << item->getData().getBirthday().month << "-" << item->getData().getBirthday().day << endl;
        for (Node* cursor = root; true;) {
            // cout << "1" << endl;
            if (cursor->getData().getBirthday() > item->getData().getBirthday()) {
                // cout << "2.5" << endl;
                if (cursor->getLeft() == nullptr) {
                    // cout << "2" << endl;
                    cursor->setLeft(item);
                    item->setParent(cursor);
                    break;
                } else {
                    // cout << "3" << endl;
                    cursor = cursor->getLeft();
                }
            } else if (cursor->getData().getBirthday() < item->getData().getBirthday()) {
                // cout << "3.5" << endl;
                if (cursor->getRight() == nullptr) {
                    // cout << "4" << endl;
                    cursor->setRight(item);
                    // cout << "4" << endl;
                    item->setParent(cursor);
                    // cout << "4" << endl;
                    break;
                } else {
                    // cout << "5" << endl;
                    cursor = cursor->getRight();
                }
            } else {
                std::cout << "Already exists!" << std::endl;
                cout << "Cursor: " << cursor->getData().getBirthday().month << "-" << cursor->getData().getBirthday().day << 
                " Item: " << item->getData().getBirthday().month << "-" << item->getData().getBirthday().day << endl << endl;
                return false;
            }
            // cout << "6" << endl;
        }

        // cout << "7" << endl;
        nodeCount++;

    }
    // cout << "8" << endl;
    return true;
}

template<class type>
bool BalancedTree<type>::remove(Node* item) {
    bool removed = false;
    while(!removed) {
        if (item->getLeft() == nullptr && item->getRight() == nullptr) {
            // cout << "Deleting: " << item->getData().getName() << endl;
            // cout << "Deletion parent: " << item->getParent()->getData().getName() << endl;
            // //cout << "Parent left child: " << item->getParent()->getLeft()->getData().getName() << endl;
            // cout << "Parent right child: " << item->getParent()->getRight()->getData().getName() << endl;
            
            //disconnect now empty node from tree
            if (item == root) {
                cout << "hello0" << endl;
                root = nullptr;
                delete item;
                removed = true;
            } else {
                if (item == item->getParent()->getLeft()) {
                    item->getParent()->setLeft(nullptr);
                } else if (item == item->getParent()->getRight()) {
                    item->getParent()->setRight(nullptr);
                }
                delete item;
                removed = true;
            }

        } else if ((item->getLeft() != nullptr && item->getRight() != nullptr) || (item->getLeft() == nullptr && item->getRight() != nullptr)) {
            swap(item, item->getRight());
        } else if (item->getLeft() != nullptr && item->getRight() == nullptr) {
            swap(item, item->getLeft());
        }
    }
    return true;
}

template<class type>
void BalancedTree<type>::fetchName(Node* rt, string requested) {
    if (rt->getLeft() == nullptr && rt->getRight() == nullptr) {
        if (rt->getData().getName() == requested)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        return;
    } else if (rt->getLeft() == nullptr && rt->getRight() != nullptr) {
        if (rt->getData().getName() == requested)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        fetchName(rt->getRight(), requested);
    } else if (rt->getLeft() != nullptr && rt->getRight() == nullptr) {
        if (rt->getData().getName() == requested)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        fetchName(rt->getLeft(), requested); 
    } else {
        if (rt->getData().getName() == requested)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        fetchName(rt->getLeft(), requested);
        fetchName(rt->getRight(), requested);
    }
}

template<class type>
void BalancedTree<type>::displayMonth(Node* rt, int month) {
    if (rt->getLeft() == nullptr && rt->getRight() == nullptr) {
        if (rt->getData().getBirthday().month == month)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        return;
    } else if (rt->getLeft() == nullptr && rt->getRight() != nullptr) {
        if (rt->getData().getBirthday().month == month)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        displayMonth(rt->getRight(), month);
    } else if (rt->getLeft() != nullptr && rt->getRight() == nullptr) {
        if (rt->getData().getBirthday().month == month)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        displayMonth(rt->getLeft(), month); 
    } else {
        if (rt->getData().getBirthday().month == month)
            cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        displayMonth(rt->getLeft(), month);
        displayMonth(rt->getRight(), month);
    }
}

template<class type>
void BalancedTree<type>::displayTree(Node* rt) {
    if (rt->getLeft() == nullptr && rt->getRight() == nullptr) {
        cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        return;
    } else if (rt->getLeft() == nullptr && rt->getRight() != nullptr) {
        cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        displayTree(rt->getRight());
    } else if (rt->getLeft() != nullptr && rt->getRight() == nullptr) {
        cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        displayTree(rt->getLeft()); 
    } else {
        cout << "Name: " << rt->getData().getName() << " | Birthday: " << rt->getData().getBirthday().month << "-" << rt->getData().getBirthday().day << endl;
        displayTree(rt->getLeft());
        displayTree(rt->getRight());
    }
}

template class BalancedTree<Node>;