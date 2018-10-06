/**
 * @file
 * @brief datastructure for the linked list in which the persons are stored
 */
#ifndef PERS_LIST
#define PERS_LIST
typedef struct LE List;
typedef struct LE ListElement;

struct LE {
	Person		data;
	ListElement *next;
};

Person emptyPerson = {"", "continel", 0};
List list;
int listItems = 0;
static int isListEmpty();
static void addToList(Person p); 
static void printList();
static void removeFromList(Person p);
static void clearList();
#endif
