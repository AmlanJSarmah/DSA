#include <iostream>
#include "stack.h"

Stack::Stack(): top{nullptr}, length {0}
{
	std::cout << "Stack Created" << std::endl;
}

void Stack::push(int value) {
	SNode* new_node = new SNode;
	new_node->data = value;
	new_node->next = nullptr;
	if (length == 0) {
		top = new_node;
	}
	else {
		new_node->next = top;
		top = new_node;
	}
	length++;
}

void Stack::pop() {
	if (length == 0) {
		std::cout << "Error: Already Empty" << std::endl;
		return;
	}
	if (length == 1){
		delete top;
		top = nullptr;
	}
	else {
		SNode* temp = top;
		top = top->next;
		delete temp;
	}
	length--;
}

SNode* Stack::peek() {
	return top;
}

bool Stack::is_empty() const {
	if (length == 0)
		return true;
	else
		return false;
}

void Stack::traverse() {
	std::cout << "Stack:\n";
	SNode* temp = top;
	while (temp) {
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "null\n";
}

