/*
	Name: Jeffrey Moe
	email: jlmoe@mix.wvu.edu
	ID: 800140003
	Assignment 4
	Spring 2018
*/
#include "stringQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Queue * CreateQueue(){
	Queue * newQueue = (Queue*) malloc(sizeof(Queue));
	if(newQueue == NULL){
		return NULL;
	}
	newQueue->front = NULL;
	return newQueue;
}

void DestroyQueue(Queue ** queuePtr){
	if(queuePtr == NULL){
		return;
	}
	while(Dequeue(*queuePtr) != NULL);
	free(*queuePtr);
	*queuePtr = NULL;
	//queuePtr == NULL;
}

void Enqueue(char * string, Queue * queue){
	if(queue == NULL || string == NULL){ //function protection
		return;
	}

	StrNode * node = CreateStrNode(string);
	if(node == NULL){	//check to make sure memory was allocated!
		return;
	}

	//case: queue is empty
	if(queue->front == NULL){
		queue->front = node;
		return;
	}
	//case: queue is not empty
	StrNode* current;
	for(current = queue->front; current->next != NULL; current = current->next);
	current->next = node;

	return;
}

char * Dequeue(Queue * queue){
	if(queue == NULL){
		return NULL;
	}

	if(queue->front == NULL){
		return NULL;
	}

	StrNode * temp = queue->front;
	char * result = temp->string;
	queue->front = temp->next;
	free(temp);
	temp = NULL;
	
	return result;
}

StrNode * CreateStrNode(char * string){
	StrNode * node = (StrNode*) malloc(sizeof(StrNode));
	if(node == NULL){
		return NULL;
	}
	node->string = string;
	node->next = NULL;
	return node;
}

const int SearchQueue(Queue * queue, char * string){
	if(queue == NULL || string == NULL){
		return 1;
	}
	if(strlen(string) < 1){
		return 1;
	}
	if(queue->front == NULL){
		return 0;
	}
	StrNode * current;
	for(current = queue->front; current->next != NULL; current = current->next){
		if(strcasecmp(current->string, string) == 0){
			free(current);
			current = NULL;
			return 1;
		}
	}

	free(current);
	current = NULL;

	return 0;
}
