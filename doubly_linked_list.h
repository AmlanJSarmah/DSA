#pragma once

class DLLNode {
public:
	int data;
	DLLNode* next;
	DLLNode* prev;
};

class DoublyLinkedList {
	DLLNode* head;
	DLLNode* tail;
	int length;
	DLLNode* at(int index);
public:
	DoublyLinkedList();
	void traverse();
	void append(int value);
	void prepend(int value);
	void insert_at(int pos, int value);
	void delete_first();
	void delete_last();
	void delete_at(int pos);
	void reverse();
};
