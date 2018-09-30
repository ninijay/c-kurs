/**
 * @file
 * @brief datastructure for the linked list in which the persons are stored
 */
#ifndef PERS_LIST
#define PERS_LIST
typedef struct l List;
typedef struct LE ListElement;

struct LE {
	Person		content;
	ListElement *next;
};

struct l {
	ListElement *head;
	int cnt;
}
Person emptyPerson = {"", "continel", 0};
List list;
#endif
