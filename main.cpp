#include "linked_list.h"

int main() {
	LinkedList ll;
	ll.append(10);
	ll.append(20);
	ll.append(30);
	ll.prepend(0);
	ll.insert_at(5, 50);
	ll.insert_at(5, 40);
	ll.traverse();
	ll.delete_first();
	ll.traverse();
	ll.delete_last();
	ll.traverse();
	ll.delete_at(3);
	ll.traverse();
	ll.delete_at(1);
	ll.traverse();
	ll.delete_at(2);
	ll.traverse();
	return 0;
}