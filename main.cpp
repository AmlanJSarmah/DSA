#include "linked_list.h"
#include "stack.h"

int main() {
	Stack s;
	s.push(0);
	s.push(10);
	s.push(30);
	s.traverse();
	s.pop();
	s.traverse();
	return 0;
}