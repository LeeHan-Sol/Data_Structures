#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char * data;
	struct Node * next;
	struct Node * prev;

	void (*init)(struct Node *, char *);
	void (*free)(struct Node *);
	void (*display)(struct Node*);
}Node;

Node * createNode(char *);

void initNode(Node *, char *);
void freeNode(Node *);

void displayNode(Node *);
#endif
