#include <iostream>
#include <limits>
#include "circular_queue.h"

CircularQueue::CircularQueue(int capacity): front {-1}, size{0}, capacity{capacity}, data{new int[capacity]}
{ 
	std::cout << "Circular Queue Created" << std::endl;
}

int CircularQueue::get_front() {
	if (size == 0)
		return INT_MIN;
	return data[front];
}

int CircularQueue::get_rear() {
	if (size == 0)
		return INT_MIN;
	int rear = (front + size - 1) % capacity;
	return data[rear];
}

void CircularQueue::enqueue(int value)
{
	if (size == capacity)
		return;
	int rear = (front + size) % capacity;
	data[rear] = value;
	size++;
}

int CircularQueue::dequeue()
{
	if (size == -1)
		return INT_MIN;
	int item = data[front];
	front = (front + 1) % capacity;
	size--;
	return item;
}
