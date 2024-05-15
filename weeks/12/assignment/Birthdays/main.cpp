#include "Birthday.hpp"
#include "Person.hpp"
#include "Node.hpp"
#include "BalancedTree.hpp"
#include <iostream>
using namespace std;

Node* makeNode(Birthday input, string name) {
	Person p;
	p.setBirthday(input);
	p.setName(name);

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

	Node* p = new Node;
	p->setData(jack);

	BalancedTree<Node> bt;
	bt.add(p);
	for (int i = 0; i < 3; i++) {
		b.day++;
		string name = "Kitty";
		bt.add(makeNode(b, name));
	}

	b.day = 18;
	for (int i = 0; i < 2; i++) {
		b.day++;
		string name = "Neko-chan";
		bt.add(makeNode(b, name));
	}

	for (int i = 0; i < 4; i++) {
		b.day--;
		b.month--;
		string name = "Hullabaloo";
		bt.add(makeNode(b, name));
	}

	bt.displayTree(bt.getRoot());
	cout << endl;

	// cout << "Retreiving all people with name Jack" << endl;
	// bt.fetchName(bt.getRoot(), "Jack");
	// cout << endl;

	bt.remove(bt.getRoot());
	cout << "Removed Jack" << endl << endl;

	cout << "Tree after removal" << endl;
	bt.displayTree(bt.getRoot());
	cout << endl;

	// cout << "Displaying everyone with a birthday month 5" << endl;
	// bt.displayMonth(bt.getRoot(), 5);
	// cout << endl << endl;
	// bt.fetchName(bt.getRoot(), "Neko-chan");

	cout << endl << bt.lefties(bt.getRoot()) << endl;
	
	
	return 0;
}
