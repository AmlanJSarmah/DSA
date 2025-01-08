#include "linked_list.h"
#include "doubly_linked_list.h"

int main() {
	DoublyLinkedList ll;
	ll.append(10);
	ll.append(20);
	ll.prepend(0);
	ll.append(30);
	ll.append(50);
	ll.insert_at(5, 40);
	ll.append(60);
	ll.append(70);
	ll.append(80);
	ll.delete_first();
	ll.delete_last();
	ll.insert_at(6, 55);
	ll.traverse();
	ll.delete_at(6);
	ll.traverse();
	ll.reverse();
	ll.traverse();
	return 0;
}