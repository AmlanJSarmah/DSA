#include <iostream>
#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList() : head{nullptr}, tail{nullptr}, length{0} {
	std::cout << "Doubly Linked List Created" << std::endl;
}

void DoublyLinkedList::traverse() {
	// Function to traverse a Linked List
	std::cout << "Doubly Linked List:\n";
	//Traverse from the direction of head
	std::cout << "Front to back\n";
	std::cout << "null==";
	DLLNode* temp = head;
	while (temp) {
		std::cout << temp->data << "==";
		temp = temp->next;
	}
	std::cout << "null\n";
	//Traverse from direction of tail
	std::cout << "Back to Front\n";
	std::cout << "null==";
	temp = tail;
	while (temp) {
		std::cout << temp->data << "==";
		temp = temp->prev;
	}
	std::cout << "null\n";
}

void DoublyLinkedList::append(int value) {
	//To add an element at the end
	// Create a new element
	DLLNode* new_node = new DLLNode();
	new_node->data = value;
	//Case I : Empty DLL
	if (length == 0) {
		head = new_node;
		tail = new_node;
	}
	//Case II : Non empty DLL
	else {
		// The current tail's next points to new node
		tail->next = new_node;
		// New Node's previous points to the current tail
		new_node->prev = tail;
		// Current tail is updated and new Node is now the tail
		tail = new_node;
		tail->next = nullptr;
	}
	length++;
}

void DoublyLinkedList::prepend(int value){
	//To add an element at the beginning
	// Create a new element
	DLLNode* new_node = new DLLNode();
	new_node->data = value;
	// Case I : No element
	if (length == 0) {
		head = new_node;
		tail = new_node;
	}

	//Case II : More than one element
	else {
		//Assign new Node's next to current head
		new_node->next = head;
		//Assign head's previous to new node
		head->prev = new_node;
		//Update the head
		head = new_node;
	}
	length++;
}

void DoublyLinkedList::insert_at(int pos, int value) {
	//Function to add an element at a given position
	//Calculate the index
	int index = pos - 1;
	// Check bounds
	if (index < 0 || index > length + 1) {
		std::cout << "Error: Out of bounds" << std::endl;
		return;
	}
	//Case I : Add to start
	if (index == 0) {
		prepend(value);
		return;
	}
	//Case II : Add to last
	if (index == length) {
		append(value);
		return;
	}
	//Case III : Insert at between
	//Create a new Node
	DLLNode* new_node = new DLLNode();
	new_node->data = value;
	//Get the before and after elements
	DLLNode* before = at(index - 1);
	DLLNode* after = before->next;
	//Assign New Node's next to after
	new_node->next = after;
	//Assign after's previous to new node
	after->prev = new_node;
	//Assign before's next to new Node
	before->next = new_node;
	//Assign new Node's previous to before
	new_node->prev = before;
	//Increament length
	length++;
}

DLLNode* DoublyLinkedList::at(int index){
	DLLNode* temp;
	//Traverse from the start if the required index is below midpoint
	if (index < (length / 2)) {
		temp = head;
		for (int i = 0; i < index; i++)
			temp = temp->next;
	}
	//Traverse from end if required index is at or above midpoint
	else {
		temp = tail;
		for (int i = length - 1; i > index; i--)
			temp = temp->prev;
	}
	return temp;
}

void DoublyLinkedList::delete_first() {
	//Case I : Empty LL
	if (length == 0) {
		std::cout << "Error: Empty Linked List" << std::endl;
		return;
	}
	//Case II : Single Element
	if (length == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	//Case III : Multiple LL
	else {
		//Assign temp i.e. the element to be deleted
		DLLNode* temp = head;
		//Reassign head
		head = head->next;
		//Delet temp and reassign head's prev pointer
		delete temp;
		head->prev = nullptr;
	}
	length--;
}

void DoublyLinkedList::delete_last() {
	//Case I : Empty LL
	if (length == 0) {
		std::cout << "Error: Empty Linked List" << std::endl;
		return;
	}
	//Case II : Single Element
	if (length == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	//Case III : Multiple LL
	else {
		//Get last second element
		DLLNode* before = at(length - 2);
		//Assign temp to the last element i.e. the element to be deleted
		DLLNode* temp = before->next;
		//Reassign tail and set it's next pointer
		tail = before;
		tail->next = nullptr;
		delete temp;
	}
	length--;
}

void DoublyLinkedList::delete_at(int pos) {
	//Delte at specific position
	//Calculate index
	int index = pos - 1;
	//Check bounds
	if (index < 0 || index > length - 1) {
		std::cout << "Error: Out of bounds" << std::endl;
		return;
	}
	//Case I : Delete from start
	if (index == 0) {
		delete_first();
		return;
	}
	//Case II : Delete from last
	if (index == length - 1) {
		delete_last();
		return;
	}
	//Case III : In between
	//Get element before the element to be deleted
	DLLNode* before = at(index - 1);
	//Assign temp to the element to be deleted
	DLLNode* temp = before->next;
	//Assign after to the element next to the temp
	DLLNode* after = before->next->next;
	//Reassign the pointers
	before->next = after;
	after->prev = before;
	//Delete the element and decrement length
	delete temp;
	length--;
}

void DoublyLinkedList::reverse() {
	if (length == 0 || length == 1)
		return;
	// Initially Assign temp to head
	// before to nullptr
	// after to next element to head
	DLLNode* temp = head;
	DLLNode* before = temp->prev;
	DLLNode* after = temp->next;
	// While we have a value in temp i.e until temp is not nullptr
	while (temp) {
		// After points to the next element of temp 
		after = temp->next;
		// Temp's next points to before element and prev pointer to after element i.e. the direction of LL gets reversed
		temp->next = before;
		temp->prev = after;
		// Before points to temp
		before = temp;
		// And temp points to after
		temp = after;
	}
	//Swap tail and head
	temp = head;
	head = tail;
	tail = temp;
}
