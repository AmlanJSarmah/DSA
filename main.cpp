#include "linked_list.h"
#include "stack.h"
#include "queue.h"

int main() {
	Queue s;
	s.enqueue(0);
	s.enqueue(10);
	s.enqueue(30);
	s.traverse();
	s.dequeue();
	s.traverse();
	return 0;
}