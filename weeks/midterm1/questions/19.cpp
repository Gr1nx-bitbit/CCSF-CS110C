#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

int countList(Node* head) {
    int count = 0;
    for (Node* cursor = head; cursor->next != nullptr; cursor = cursor->next) {
        if (cursor->next == head) {
            count++;
            break;
        } else {
            count++;
        }
    }
    return count;
}

int main(void) {
    Node* hey = new Node;
    Node* bye = new Node;
    Node* oof = new Node;
    Node* yip = new Node;
    Node* pip = new Node;
    hey->data = 3;
    bye->data = 4;
    oof->data = 5;
    yip->data = 6;
    hey->next = bye;
    bye->next = oof;
    oof->next = yip;
    yip->next = pip;
    pip->next = hey;
    cout << countList(hey) << endl;
    return 0;
}
