#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "Node.hpp"

template <class type>
class BalancedTree {
    private:
        int nodeCount;
        Node* root;
        bool balanced(void);
        // int getHeight(Node*, int);
        
    public:
        BalancedTree(void);
        bool isEmpty(void);
        bool add(Node*);
        bool remove(Node*);
        void displayMonth(int);
        int getHeight(Node*, int);
        Node* getRoot() { return root; }
};

#endif