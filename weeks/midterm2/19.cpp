#include <iostream>
using namespace std;

class BinaryNode
{
public:
    string item;
    BinaryNode *leftChildPtr;
    BinaryNode *rightChildPtr;
};

int shortName(BinaryNode* cursor);

int main(void) {
    BinaryNode* head = new BinaryNode;
    head->item = "bob";
    head->leftChildPtr = new BinaryNode;
    head->rightChildPtr = new BinaryNode;

    head->leftChildPtr->item = "cor";
    head->rightChildPtr->item = "bil";

    head->leftChildPtr->leftChildPtr = new BinaryNode;
    head->leftChildPtr->leftChildPtr->item = "co34n";
    head->leftChildPtr->rightChildPtr = new BinaryNode;
    head->leftChildPtr->rightChildPtr->item = "bill";

    head->rightChildPtr->leftChildPtr = new BinaryNode;
    head->rightChildPtr->leftChildPtr->item = "con";
    head->rightChildPtr->rightChildPtr = new BinaryNode;
    head->rightChildPtr->rightChildPtr->item = "bl23";

    int num = shortName(head);
    cout << num << endl;
    return 0;
}

int shortName(BinaryNode* cursor) {
    int length = 0;
    if (cursor == nullptr) {
        return 0;
    } else {
        if (cursor->item.length() <= 3) {
            length++;
        }
        length += shortName(cursor->leftChildPtr);
        length += shortName(cursor->rightChildPtr);
    }
    return length;
}