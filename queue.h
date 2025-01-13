#pragma once

class QNode {
public:
	int data;
	QNode* next;
};

class Queue {
	QNode* q_front;
	QNode* q_rear;
	int length;
public:
	Queue();
	void enqueue(int value);
	void dequeue();
	QNode* front();
	QNode* read();
	int size() const;
	void traverse();
};
