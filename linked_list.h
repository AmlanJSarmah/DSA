#pragma once

class Node {
public:
	int data;
	Node* next;
};

class LinkedList {
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList();
	void traverse();
	void append(int value);
};
