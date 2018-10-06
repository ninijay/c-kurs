#include <stdio.h>
#include <stdlib.h>
#include "pers.h"
/**
 * @file
 * @brief implementation of the Person datastructure
 */

/**
 * @brief print a given person
 */
void printPerson(Person p)
{
	(void)printf("Name:\t\t%20s\n", p.name);
	(void)printf("First Name:\t%20s\n", p.firstname);
	(void)printf("Age:\t\t%d\n", p.age);
}

/**
 * @brief compare two persons
 * @returns result of strcmp (0 =false, 1=true)
 */
int prscmp(Person p1, Person p2)
{
	int cmp = 0;
	cmp = strcmp(p1.name, p2.name);
	if(cmp == 0){
		cmp = strcmp(p1.firstname, p2.firstname);
	}
	if(cmp == 0){
		cmp = p1.age -p2.age;
	}
	return cmp;
}
