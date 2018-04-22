#include "bonus_points.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
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

void ReverseString(char * string){
	Stack * reverseStack = CreateStack();
	int i = 0;
	while(string[i] != '\0'){
		Push(string[i++], reverseStack);
	}
	i = 0;
	while(reverseStack->top != NULL){
		string[i++] = Pop(reverseStack);
	}
}
