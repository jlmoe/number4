#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Node * CreateNode(const void * data){
	Node * node = (Node*) malloc(sizeof(Node));
	if(node == NULL) return NULL;
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

Stack * CreateStack(){
	Stack * stack = (Stack*) malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}

void DestroyStack(Stack ** stack_ptr){
	if(stack_ptr == NULL){
		return;
	}
	while(Pop(*stack_ptr) != NULL);
	free(*stack_ptr);
	*stack_ptr = NULL;
}

void Push(const void* data, Stack * stack){
	Node* node =  CreateNode(data);

	if(stack == NULL || data == NULL){
		free(node);
		node = NULL;
	}

	else if(stack -> top == NULL){
		stack->top = node;
	}
	else{
		node->previous = stack->top;
		stack->top = node;
	}

}

const void * Pop(Stack * stack){
	if(stack == NULL) return NULL;
	else if(stack->top == NULL){
		return NULL;
	}

	Node * node  = stack->top;
	stack->top = node->previous;
	node->previous = NULL;
	const void * data = node->data;
	free(node);
	node = NULL;
	return data;
}

