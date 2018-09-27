#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFERSIZE 32
#define MAXLISTSIZE 100

char *wordlist[100];


/**
 * @brief compare the first characters of strings with strcmp
 * @param s1 first string
 * @param s2 second string to compare
 */
int cmpStr(const void *s1, const void *s2)
{
	//0 -> first chars is equal, else different
	return strcmp(*(char **)s1, *(char **)s2);
}

/**
 * @brief save a word in a wordlist and return the wordcount
 * @param wordlist the wordlist to store the words in
 * @param word word to add to wordlist
 * @param wordc number of words currently in list
 */
int storeWord(char *wordlist[], char word[], int wordc){
	int len = strlen(word);
	if(len>1){
		char *array=(char*)malloc(len);
		strcpy(array,word);
		wordlist[wordc] = array;
		wordc++;
	}
	return wordc;
}


/**
 * @brief print all words in list
 * @param wordlist wordlist to print
 * @param wordcount number of words
 */
void printWordList(char *wordlist[], int wordc){
	for(int i=0; i < wordc; i++){
		(void)printf("%s", wordlist[i]);
	}
}

/**
 * @brief main entry point.
 * @returns EXIT_SUCCESS on success.
 */ 
int main(int argc, char *argv[]){
	char c[MAXBUFFERSIZE];
	int wordc=0;
	
	(void)printf("Bitte geben Sie die eine Liste von Worten ein.\nEinzelne wörter durch Return terminiert, Ende der Sequenz mit \"ZZZ\":\n");
	while(fgets(c, MAXBUFFERSIZE, stdin) != NULL && strcmp(c, "ZZZ\n") != 0){
		wordc=storeWord(wordlist, c, wordc);
	};
	
	// sort list
	(void)qsort(wordlist, wordc, sizeof(char*), cmpStr);
	
	//print
	printWordList(wordlist, wordc);
	return EXIT_SUCCESS;
}

