#pragma once

class SNode {
public:
	int data;
	SNode* next;
};

class Stack {
	SNode* top;
	int length;
public:
	Stack();
	void push(int value);
	void pop();
	SNode* peek();
	bool is_empty() const;
	void traverse();
};
