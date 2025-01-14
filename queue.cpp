#include <iostream>
#include "queue.h"

Queue::Queue() : q_front {nullptr}, q_rear {nullptr}, length {0}
{
	std::cout << "Queue Created" << std::endl;
}

void Queue::enqueue(int value)
{
	QNode* new_node = new QNode;
	new_node->data = value;
	new_node->next = nullptr;
	if (length == 0) {
		q_front = new_node;
		q_rear = new_node;
	}
	else {
		q_rear->next = new_node;
		q_rear = new_node;
	}
	length++;
}

void Queue::dequeue()
{
	if (length == 0) {
		std::cout << "Error: Nothing to delete" << std::endl;
		return;
	}
	if (length == 1) {
		delete q_front;
		q_front = nullptr;
		q_rear = nullptr;
	}
	else{
		QNode* temp = q_front;
		q_front = q_front->next;
		delete temp;
	}
	length--;
}

QNode* Queue::front()
{
	return q_front;
}

QNode* Queue::read()
{
	return q_rear;
}

int Queue::size() const
{
	return length;
}

void Queue::traverse() {
	std::cout << "Queue:\n";
	QNode* temp = q_front;
	while (temp) {
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "null\n";
}
