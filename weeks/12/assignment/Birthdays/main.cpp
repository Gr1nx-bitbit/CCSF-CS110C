#include "Birthday.hpp"
#include "Person.hpp"
#include "Node.hpp"
#include "BalancedTree.hpp"
#include <iostream>
using namespace std;

Node* makeNode(Birthday input) {
	Person p;
	p.setBirthday(input);

	Node* cursor = new Node;
	cursor->setData(p);
	return cursor;
}

int main(void) {
	Birthday b;
	b.day = 21;
	b.month = 5;

	Person jack;
	jack.setName("Jack");
	jack.setBirthday(b);
	cout << jack.getName() << endl;

	Node* p = new Node;
	p->setData(jack);

	BalancedTree<Node> bt;
	bt.add(p);
	for (int i = 0; i < 3; i++) {
		b.day++;
		bt.add(makeNode(b));
	}

	b.day = 18;
	for (int i = 0; i < 2; i++) {
		b.day++;
		bt.add(makeNode(b));
	}

	cout << bt.getHeight(bt.getRoot(), 0) << endl;

	for (Node* cursor = bt.getRoot(); cursor != nullptr; cursor = cursor->getRight()) {
		cout << "0" << endl;
	}
	
	return 0;
}
