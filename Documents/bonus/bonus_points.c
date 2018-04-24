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

	if(string == NULL || numWords == NULL) return NULL;//NULL protection
	//Variable initialization
	char ** result;
//	char * currentSubstring;
	char * split = " ";
	fprintf(stdout, "MEMES\n");

	int stringLength = strlen(string);
	Queue * wordQ = CreateQueue();
	fprintf(stdout, "MEMES\n");

/*	for(char * str_ptr = string; *str_ptr != '\0'; str_ptr++){

	}
*/

	//char * currentChar = string;
	//char * startOfWord = currentChar;
	int startOfWord = string;
	int currentChar = string;
	char * substring = (char*) malloc(sizeof(char) * stringLength);

	int diff = 0;
	int noWordsFlag = FALSE;
	*numWords = 0;
	int index = 0;

	fprintf(stdout, "MEMES\n");

	while(index < stringLength){
		fprintf(stdout, "iteration %d\n", index);
		if(string[currentChar] == * split){
			diff = currentChar - startOfWord;
			int i = 0;
			for(i = 0; i < diff; i++){
				substring[i] = string[startOfWord];
			}
			substring[i] = '\0';
			if(SearchQueue(wordQ, substring)){
				Enqueue(substring, wordQ);
				*(numWords)++;
				startOfWord = ++currentChar;
			}
			else{
				startOfWord = ++currentChar;
			}
		}

		currentChar++;
	}

	free(substring);


	//look for words
/*	while(i < stringLength){
		if(*currentChar == *split){
			diff = currentChar - currentSubstring;
			currentSubstring[diff+1] = '\0';
			if(SearchQueue(wordQ, currentSubstring)){
				Enqueue(currentSubstring, wordQ);
				(*numWords)++;
				currentSubstring = currentSubstring + diff + 1;
			}
			else{
				currentSubstring = currentSubstring + diff + 1;
			}
		}
		currentChar++;
		i++;
	}
*/


	fprintf(stdout, "MEMES\n");

	if(numWords == 0) {
		noWordsFlag = TRUE;
	}
	result = (char**) malloc(sizeof(char*) * (*numWords) + (noWordsFlag * sizeof(char*)));
	if(result == NULL){
		return NULL;
		free(result);
	}

	for(int i = 0; i < *numWords; i++){
		char * temp = Dequeue(wordQ);
		result[i] = temp;
	}
	DestroyQueue(&wordQ);
	fprintf(stdout, "MEMES\n");

	return result;
}


int FindSubstring(const char * string, const char * substring){
	if(string == NULL || substring == NULL){
		return -1;
	}

	int position;
	int positionFound = FALSE;
/*	while(position < strlen(string) && !positionFound){
		for(int i = 0; position + i < strlen(string) && !positionFound; i++){
			if(string[position + i] != substring[i]){
				if(position + i == strlen(substring - 1)){
					positionFound = TRUE;
				}
			}
		}
		position++;
	}
*/
	int i;
	while(!positionFound && position < strlen(string) ){
		i = 0;
		while(string[position + i] == substring[i]){
			printf(" !! \n");
			if(i == strlen(substring) - 1){
				positionFound = TRUE;
			}
			i++;
		}
		if(positionFound) break;
		position++;
	}

	if(!positionFound){
		position = -1;
	}

	return position;
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
