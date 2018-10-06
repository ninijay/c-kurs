#include <stdio.h>
#include <stdlib.h>
#include "pers.h"
#include "list.h"

/**
 * @file
 * @brief implementation of the linked list
 */

/**
 * @brief check if lis tis empty
 *
 */
static int isListEmpty()
{
	return (listItems== 0);
}

/**
 * @brief add a person to the list
 */
static void addToList(Person p)
{
	(void)printf("Add %20s %20s %3d\n", p.name, p.firstname, p.age);
	ListElement *new = malloc(sizeof(ListElement));
	new->data = p;
	new->next = &list;

	if(isListEmpty())
	{
		list.next= &*new;
	}else{
		ListElement *current = &list;
		do{
			Person nextPerson = (*current->next).data;
			if(!prscmp(p, nextPerson) && &*current->next != &list){
				new->next = &*current->next;
				break;
			}
			current = &*current->next;
		}while(&*current->next != &list);
		current->next = &*new;
	}
	listItems++;
}

/**
 * @brief print the persons in the list
 */
static void printList()
{
	int cnt = 0;
	ListElement *next = &list;
	do{
		Person p = (Person) next->data;
		if(&*next != &list){
			(void)printf("%d: %20s %20s\t%3d\n", ++cnt, p.name, p.firstname, p.age); 
		}
		next = &*next->next;
	}while(&*next != &list);
	
}

/**
 * @brief remove a given person from the list
 */
static void removeFromList(Person p)
{
	(void)printf("Remove %20s %20s %3d\n", p.name, p.firstname, p.age);
	ListElement *current = &list;
	do{
		Person next = (*current->next).data;
		if(prscmp(p, next)){
			ListElement *toBeFreed = &*current->next;
			current->next = &*(*current->next).next;
			free(toBeFreed);
			break;
		}
		current = &*current->next;
	}while(&*current->next != &list);
}

/**
 * @breif remove all persons from the list
 */
static void clearList(void)
{
	ListElement *next = &*list.next;
	while(&*next != &list){
		Person p = (Person) next->data;
		removeFromList(p);
		next = &*next->next;
	}
	list.data = emptyPerson;
	list.next = &list;
}
