#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList() : head{ nullptr }, tail{ nullptr }, length{ 0 } {
	std::cout << "Linked List Created" << std::endl;
}

void LinkedList::traverse() {
	// Function to traverse a Linked List
	// Starts with a temporary pointer at head and keep changing the pointer to next until it reaches nullptr.
	// Before updating the pointer the current value is printed followed by a "->"
	/*
		0->10->20->30->40->50->null	
		^
		temp

		0->10->20->30->40->50->null
			^
			temp

		.
		.
		.

		0->10->20->30->40->50->null
								^		
								temp
	*/
	std::cout << "Linked List:\n";
	Node* temp = head;
	while (temp) {
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "null\n";
}

void LinkedList::append(int value) {
	// Function to add a Node at the end of LL
	// Create a new Node
	Node* new_node = new Node();
	new_node->data = value;
	// CASE 1 : If LL is empty
	// Head points to new node as well as tail, length is increamented 
	if (length == 0) {
		head = new_node;
		tail = new_node;
	}
	// CASE 2 : If LL is not empty
	// the next of tail i.e. currently pointing to null points to new node.
	// tail is then assigned to new node and length is increamented
	else {
		tail->next = new_node;
		tail = new_node;
	}
	length++;
}

void LinkedList::prepend(int value) {
	// Function to add a Node at start of LL
	// A new Node is created
	Node* new_node = new Node();
	new_node->data = value;
	// CASE 1 : if LL is empty
	// head and tail points to new node and length is increamented
	if (length == 0) {
		head = new_node;
		tail = new_node;
	}
	// CASE 2 : if LL is not empty
	// new Node's next points to current head
	// head is assigned to new node and length is increamented
	else {
		new_node->next = head;
		head = new_node;
	}
	length++;
}

Node* LinkedList::at(int index) {
	// Helper function to get a Node at an index
	// Assign temp to head
	Node* temp = head;
	// Move temp to next Node until the value of i that starts at 0 is less than index
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}

void LinkedList::insert_at(int pos, int value) {
	// Function to add an element at an index
	int index = pos - 1;
	if(index < 0 || index > length){
		std::cout << "Error: Index Out Of Bounds" << std::endl;
		return;
	}
	// CASE 1 : Insert at start
	if (index == 0) {
		prepend(value);
		return;
	}
	// CASE 2 : Insert at end
	if (index == length) {
		append(value);
		return;
	}
	// CASE 3: In Between
	// Create a new node
	Node* new_node = new Node();
	new_node->data = value;
	// Get the node before required index
	/*
		0->10->20->40->null
		Here if we want to insert 30 between 20 and 40 i.e. index 3

		We find element at previous index here 2

		0->10->20->40->null
				^
				b	30
	*/
	Node* before = at(index - 1);
	/*
		We assign after to the element next to before

		0->10->20->40->null
				^	^
				b	a	30
	*/
	Node* after = before->next;
	/*
		The new Node's next now points to the node poiting to after

					a
		0->10->20->40->null	
				^	^
				b	|
					30	
	*/
	new_node->next = after;
	/*
		The before's next now points to new node

		0->10->20->30->40->null	
				^		^
				b		a
	*/
	before->next = new_node;
	length++;
}

int LinkedList::delete_first(){
	// Function to delete first element
	// CASE 1 : If list is empty
	if (length == 0) {
		std::cout << "ERROR:Nothing to delete" << std::endl;
		return -1;
	}
	// CASE 2 : If list has one element delete it and both head and tail points to null also the length is decreased,
	if (length == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	// CASE 3: For LL with length > 1
	// Assign the current head to temp
	// Assign head to current head's next
	// Delete the temp
	// Decreament the length
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	length--;
	return 0;
}

int LinkedList::delete_last() {
	// To delete last element
	// CASE 1 : if LL is empty
	if (length == 0) {
		std::cout << "ERROR:Nothing to delete" << std::endl;
		return -1;
	}
	// CASE 2 : if LL has 1 element
	if (length == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	// CASE 3 : If LL has element > 1
	// Get the last second element
	// Delete the last element
	// Assign tail to last second element
	// Last second element i.e. current tail's next points to null
	// Length is decreamented
	else {
		Node* before = at(length - 2);
		delete tail;
		tail = before;
		tail->next = nullptr;
	}
	length--;
	return 0;
}

int LinkedList::delete_at(int pos) {
	// To delete from particular position
	// Calculate the index based on position
	int index = pos - 1;
	// Check bounds
	if (index < 0 || index > length - 1) {
		std::cout << "ERROR: Index Out of Bounds" << std::endl;
		return -1;
	}
	// CASE 1 : Delete first element
	if (index == 0) {
		if (delete_first() == -1)
			return -1;
		return 0;
	}
	// CASE 2 : Delete last element
	if(index == length-1){
		if (delete_last() == -1)
			return -1;
		return 0;
	}
	// CASE3 : Delete from between
	// Get the element before the required index i.e. if index 3 is to be deleted get index 2
	Node* before = at(index - 1);
	// Assign temp to index to be deleted i.e. before->next
	Node* temp = before->next;
	// Assign before->next to be the next element to next element i.e. if 3 is to be deleted 2 is before assign 2's next to 4
	before->next = before->next->next;
	// Delete the element and decreament the length
	delete temp;
	length--;
	return 0;
}