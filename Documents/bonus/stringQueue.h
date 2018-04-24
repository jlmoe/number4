/*
	Name: Jeffrey Moe
	email: jlmoe@mix.wvu.edu
	ID: 800140003
	Assignment 4
	Spring 2018
*/

#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

typedef struct StrNode{
	char * string;
	struct StrNode * next;
}StrNode;

typedef struct Queue{
	StrNode * front;
}Queue;

Queue * CreateQueue();

void DestroyQueue(Queue ** queue);

void Enqueue(char * string, Queue * queue);

char * Dequeue(Queue * queue);

StrNode * CreateStrNode(char * string);

const int SearchQueue(Queue * queue, char * string);

#endif
