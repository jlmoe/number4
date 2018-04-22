#include "bonus_points.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "stringQueue.h"

char * DecimalToBinaryString(unsigned int decimal){
	char * result;
	unsigned int decimalCpy = decimal;
	unsigned int bit;
	int i = 0;

	while(decimalCpy > 0){
		decimalCpy /= 2;
		i++;
	}
	result = (char*) malloc(sizeof(char) * i + 1);
	if(result == NULL) return NULL;
	i = 0;
	while(decimal > 0){
		bit = decimal % 2;
		decimal /= 2;
		if(bit == 0) result[i++] = '0';
		else if(bit == 1) result[i++] = '1';
		else{
			return NULL;
		}
	}
	result[i++] = '\0';
	ReverseString(result);
	puts(result);
	return result;
}

char ** FindUniqueWords(const char * string, int * numWords){

	if(string == NULL || numWords == NULL) return NULL;

	char ** result;
	char * currentSubstring;
	char * split = " ";
	int stringLength = strlen(string);
	Queue wordQ = CreateQueue();
	strcpy(currentSubstring, string);
	char * currentChar = currentSubstring;
	int diff = 0;
	int i = 0;
	int noWordsFlag = FALSE;
	*numWords = 0;
	while(i < stringLength){
		if(*currentChar == *split){
			diff = currentChar - currentSubstring;
			currentSubstring[diff+1] = '\0';
			if(SearchQueue(wordQ, currentSubstring)){
				Enqueue(currentSubstring, wordQ);
				*numWords++;
				currentSubstring = currentSubstring + diff + 1;
			}
			else{
				currentSubstring = currentSubstring + diff + 1;
			}
		}
		currentChar++;
		i++;
	}

	if(numWords == 0) {
		noWordsFlag = TRUE;
	}
	result = (char**) malloc(sizeof(char*) * numWords + (noWordsFlag * sizeof(char*)));
	if(result == NULL) return NULL;

	for(i = 0; i < numWords; i++){
		result[i] = Dequeue(wordQ);
	}
	return result;
}




void ReverseString(char * string){
	Stack * reverseStack = CreateStack();
	int i = 0;
	while(string[i] != '\0'){
		Push(string[i++], reverseStack);
	}
	i = 0;
	while(reverseStack->top != NULL){
		string[i++] = (char) Pop(reverseStack);
	}
}
