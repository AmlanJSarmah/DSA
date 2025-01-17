#pragma once

class CircularQueue {
	int* data;
	int front, size, capacity;
public:
	CircularQueue(int capacity);
	int get_front();
	int get_rear();
	void enqueue(int value);
	int dequeue();
};
