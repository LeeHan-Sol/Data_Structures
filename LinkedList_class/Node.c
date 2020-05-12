#include "Node.h"

Node * createNode(char * data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));

	newNode->init = initNode;
	newNode->init(newNode, data);

	return newNode;
}

void initNode(Node * node, char * data)
{
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	node->free = freeNode;
	node->display = displayNode;
}

void freeNode(Node * node)
{
	free(node);
}

void displayNode(Node * node)
{
	printf("%s (%p)\n", node->data, node);
}

