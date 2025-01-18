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
	//We find the last element. (front + size - 1) % capacity returns the last element with a value
	int rear = (front + size - 1) % capacity;
	return data[rear];
}

void CircularQueue::enqueue(int value)
{
	if (size == capacity)
		return;
	//We find the first free index and insert a new value. (front + size) % capacity returns the first index where we can insert a value
	int rear = (front + size) % capacity;
	data[rear] = value;
	size++;
}

int CircularQueue::dequeue()
{
	if (size == -1)
		return INT_MIN;
	int item = data[front];
	//We move the front to next index, hence the previous front becomes free to use. Hence, we decrement the size
	front = (front + 1) % capacity;
	size--;
	return item;
}
