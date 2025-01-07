#include "linked_list.h"

int main() {
	LinkedList ll;
	ll.append(10);
	ll.append(20);
	ll.append(30);
	ll.prepend(0);
	ll.traverse();
	return 0;
}