#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

typedef struct List
{
	Node * head;
	Node * tail;

	void (*init)(struct List *);
	void (*free)(struct List *);

	void (*pushFront)(struct List *, char *);
	void (*pushRear)(struct List *, char *);
	void (*pushByIndex)(struct List *, char *, int);
	int (*pushAfterData)(struct List *, char *, char *);

	void (*popFront)(struct List *);
	void (*popRear)(struct List *);
	void (*popByIndex)(struct List *, int);
	void (*popData)(struct List *, char *);

	void (*searchByIndex)(struct List *, int);
	void (*searchRear)(struct List *);
	void (*searchData)(struct List *, char *);

	int (*isEmpty)(struct List *);
	int (*size)(struct List *);
	void (*display)(struct List *);
	void (*rDisplay)(struct List *);
	void (*displayFirstAndLast)(struct List *);
}List;

List * createList();

void initList(List *);
void freeList(List *);

int isEmpty(List *);
void pushFront(List *, char *);
void pushRear(List *, char *);
void pushByIndex(List *, char *, int); 
int pushAfterData(List *, char *, char *);
void popFront(List *);
void popRear(List *);
void popByIndex(List *, int);
void popData(List *, char *);

void searchByIndex(List *, int);
void searchRear(List *);
void searchData(List *, char *);
int size(List *);
void displayList(List *);
void rDisplayList(List *);
void displayListFirstAndLast(List *);

#endif
