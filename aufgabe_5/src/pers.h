#ifndef PERS
#define PERS

/**
 * @file
 * @brief definition of the person-struct
 */

typedef struct {
	char name[20];
	char firstname[20];
	unsigned int age;
} Person;

void printPerson(Person p);
int prscmp(Person p1, Person p2);
#endif
