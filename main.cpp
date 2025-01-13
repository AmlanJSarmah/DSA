#include "linked_list.h"
#include "doubly_linked_list.h"
#include "stack.h"
#include "queue.h"

int main() {
	Queue q;
	q.enqueue(0);
	q.enqueue(10);
	q.enqueue(30);
	q.traverse();
	q.dequeue();
	q.traverse();
	return 0;
}