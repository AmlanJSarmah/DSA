#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList() : head{ nullptr }, tail{ nullptr }, length{ 0 } {
	std::cout << "Empty Linked List Created" << std::endl;
}

void LinkedList::traverse() {
	Node* temp = head;
	while (temp) {
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "null\n";
}

void LinkedList::append(int value) {
	Node* new_node = new Node();
	new_node->data = value;
	if (head == nullptr) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
	length++;
}