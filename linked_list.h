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
	Node* at(int index);

public:
	LinkedList();
	void traverse();
	void append(int value);
	void prepend(int value);
	void insert_at(int pos, int value);
};
