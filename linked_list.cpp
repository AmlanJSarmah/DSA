#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList() : head{ nullptr }, tail{ nullptr }, length{ 0 } {
	std::cout << "Linked List Created" << std::endl;
}

void LinkedList::traverse() {
	std::cout << "Linked List:\n";
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
	if (length == 0) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
	length++;
}

void LinkedList::prepend(int value) {
	Node* new_node = new Node();
	new_node->data = value;
	if (length == 0) {
		head = new_node;
		tail = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}
	length++;
}

Node* LinkedList::at(int index) {
	Node* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}

void LinkedList::insert_at(int pos, int value) {
	int index = pos - 1;
	if(index < 0 || index > length){
		std::cout << "Error: Index Out Of Bounds" << std::endl;
		return;
	}
	if (index == 0) {
		prepend(value);
		return;
	}
	if (index == length) {
		append(value);
		return;
	}
	Node* new_node = new Node();
	new_node->data = value;
	Node* before = at(index - 1);
	Node* after = before->next;
	new_node->next = after;
	before->next = new_node;
	length++;
}