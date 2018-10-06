/**
 * @file
 * @brief main class - starting point of application
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pers.h"
#include "list.h"
#include "pers.c"
#include "list.c"
typedef enum
{
INSERT, REMOVE, SHOW, CLEAR, END, INVALID
} Input;

/**
 * @brief print spacer line
 */
void printSpacer(void){
	(void)printf("--------------------------------------------------\n");
}

/**
 * @brief endlessloop for input return and EOF
 */
void flushIt(void){
	int c;
	while ((c=getchar()) != EOF && c != '\n');
}

/**
 * @brief read person-data from commandline
 * @returns the new person from input data
 */
Person readPerson(void){
	Person person;
	flushIt();

	(void)printf("First Name:");
	fgets(&person.firstname, 20, stdin);
	(void)printf("Name:");
	fgets(&person.name, 20, stdin);
	(void)printf("Age:");
	scanf("%d", &person.age);
	printf("\n");

	strtok(person.firstname, "\n");
	strtok(person.name, "\n");

	return person;
}

/**
 * @brief read command symbols
 * @returns input-enum declared for this symbol
 */
Input readInput(void){
	char input;
	do
		input = getchar();
	while(isspace(input));

	if(toupper(input) == 'E')
		return END;
	if(toupper(input) == 'I')
		return INSERT;
	if(toupper(input) == 'R')
		return REMOVE;
	if(toupper(input) == 'S')
		return SHOW;
	if(toupper(input) == 'C')
		return CLEAR;

	return INVALID;
}

/**
 * @brief removes Person via cli input
 */
void rmprs(void) 
{
	printSpacer();
	(void)printf("Remove\n");
	printSpacer();
	Person p = readPerson();
	removeFromList(p);
}

/**
 * @brief add a person to the list
 */
void insprs(void)
{
	printSpacer();
	(void)printf("Insert\n");
	printSpacer();
	Person p = readPerson();
	addToList(p);
}

/**
 * @brief prints all persons
 */
void catprs()
{
	printSpacer();
	(void)printf("Show\n");
	printSpacer();
	printList();
}

/**
 * @brief initialize personlist
 */
void initlist()
{
	list.data = emptyPerson;
	list.next = &list;
}

/**
 * @brief clears person list
 */
void dropprs()
{
	printSpacer();
	(void)printf("Clear\n");
	printSpacer();
	clearList();
	initlist();
}


/**
 * @brief perfomes the command choosen via the menu
 */
void executeInput(Input command)
{
	switch(command){
		case INVALID:
			(void)printf("Invalid command!\n");
			break;
		case INSERT:
			insprs();
			break;
		case REMOVE:
			rmprs();
			break;
		case SHOW:
			catprs();
			break;
		case CLEAR:
			dropprs();
			break;
		default:
			return;
	}
}


/**
 * @brief Main entry point.
 * @returns EXIT_SUCCESS(=0) on success,
 *	    EXIT_FAILURE else
 */
int main(void)
{
	initlist();
	Input command = INVALID;
	(void) printf("I(nsert), R(emove), S(how), C(lear), E(nd):\n");
	while(command != END){
		printSpacer();
		(void)printf("Enter Input:\n");
		command = readInput();
		executeInput(command);
	}
	return EXIT_SUCCESS;
}


