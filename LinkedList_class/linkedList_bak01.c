#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;

	void (*init)(struct Node *);
}Node;

typedef struct List
{
	Node * head;
	Node * tail;

	void (*init)(struct List *);
	void (*addFront)(struct List *, Node *);
	void (*addRear)(struct List *, Node *);
	void (*display)(struct List *);
}List;

void initNode(Node *);

void initList(List *);
void addFront(List *, Node *);
void addRear(List *, Node *);
void displayList(List *);

int main()
{
	List * list = (List *)malloc(sizeof(List));
	list->init = initList;
	list->init(list);

	Node * node01 = (Node *)malloc(sizeof(Node));
	node01->init = initNode;
	node01->init(node01);
	node01->data = 1;

	Node * node02 = (Node *)malloc(sizeof(Node));
	node02->init = initNode;
	node02->init(node02);
	node02->data = 2;

	Node * node03 = (Node *)malloc(sizeof(Node));
	node03->init = initNode;
	node03->init(node03);
	node03->data = 3;

	Node * node00 = (Node *)malloc(sizeof(Node));
	node00->init = initNode;
	node00->init(node00);
	node00->data = 0;

	printf("node의 값(주소) : %d (%p)\n", node01->data, node01);

	list->addFront(list, node01);
	list->addRear(list, node02);
	list->addRear(list, node03);
	list->addFront(list, node00);

	list->display(list);

	printf("list->head, tail : {%d (%p)}, {%d (%p)}\n", list->head->data, list->head, list->tail->data, list->tail);

	return 0;
}

void initNode(Node * node)
{
	node->data = 0;
	node->next = NULL;
}

void initList(List * list)
{
	list->head = NULL;
	list->tail = NULL;

	list->addFront = addFront;
	list->addRear = addRear;
	list->display = displayList;
}

void addFront(List * list, Node * node)
{
	node->next = list->head;
	list->head = node;
	if(list->tail == NULL) list->tail = node;
}

void addRear(List * list, Node * node)
{
	list->tail->next = node;
	list->tail = node;

	if(list->head == NULL) list->head == node;
}

void displayList(List * list)
{
	printf("List 항목\n");
	
	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		printf("%4d (%p)\n", temp->data, temp);
	}
}
