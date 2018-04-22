#ifndef STACK_H
#define STACK_H

typedef struct Node{
	void * data;
	struct Node * next;
	struct Node * previous;
}Node;

typedef struct Stack{
	Node * top;
}Stack;

//init
Node * CreateNode(const void * data);
Stack * CreateStack();

//destroy
void DestroyStack(Stack ** stack_ptr);

//push
void Push(const void * data, Stack * stack);

//pop
const void * Pop(Stack * stack);

#endif
