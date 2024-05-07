#include "Birthday.hpp"
#include "Person.hpp"
#include "Node.hpp"
#include "BalancedTree.hpp"
#include <iostream>
using namespace std;

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
	cout << p->getData().getBirthday().day << endl;

	BalancedTree<Node> bt;
	cout << "hello" << endl;
	bt.add(p);
	cout << "hello0" << endl;
	
	return 0;
}
