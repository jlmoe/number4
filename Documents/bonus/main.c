#include "bonus_points.h"
#include <stdio.h>

int main(){
	unsigned int decToBin = 254;
	puts(DecimalToBinaryString(decToBin));
//	char * string = "Hello there young fellow there is young hello";
	char * string = "This is a long string!";

/*	int * numWords;
	char ** listOfUniqueWords = FindUniqueWords(string, numWords);
	printf("%d\n", *numWords);
	for(int i = 0; i < *numWords; i++){
		printf("%s ", listOfUniqueWords[i]);
	}
	puts("");

*/
	printf("%d\n",(FindSubstring(string, "GEEm")));

	return 0;
}
