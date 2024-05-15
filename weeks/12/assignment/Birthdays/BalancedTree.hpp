#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "Node.hpp"
#include <string>

template <class type>
class BalancedTree {
    private:
        int nodeCount;
        Node* root;
        bool balanced(void);
        int getHeight(Node*, int);
        Node* getNodeatHeight(Node*, int, int);
        void swap(Node*, Node*);
        
    public:
        BalancedTree(void);
        bool isEmpty(void);
        bool add(Node*);
        bool remove(Node*);
        void fetchName(Node*, std::string);
        void displayMonth(Node*, int);
        void displayTree(Node*);
        // int getHeight(Node*, int);
        // Node* getNodeatHeight(Node*, int, int);
        Node* getRoot() { return root; }
        int lefties(Node*);
        // bool balanced(void);
};

#endif