#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char data[20];
	struct Node * next;
}Node;

typedef struct List
{
	Node * head;
}List;

int main()
{
	List * list;
	list = createList();
	
	printf("list create\n");
	printList(list);
	puts("");
	
	printf("input Front\n");
	insertFront(list, "apple");
	printList(list);
	puts("");

	printf("input Rear\n");
	insertRear(list, "banana");
	printList(list);
	puts("");

	printf("input Rear\n");
	insertRear(list, "grape");
	printList(list);
	puts("");

	printf("remove Front\n");
	removeFront(list);
	printList(list);
	puts("");

	printf("input Front\n");
	insertFront(list, "orange");
	printList(list);
	puts("");

	printf("input Index 2\n");
	insertByIndex(list, "apple", 3);
	printList(list);
	puts("");

	printf("remove Index 4\n");
	removeByIndex(list, 4);
	printList(list);
	puts("");

	printf("insert Index 100\n");
	insertByIndex(list, "blueberry", 100);
	printList(list);
	puts("");

	printf("remove Index 100\n");
	removeByIndex(list, 100);
	printList(list);
	puts("");

	printf("search Data\n");
	searchData(list, "apple");
	puts("");

	printf("search Index 2\n");
	searchByIndex(list, 2);
	puts("");

	printf("free(list)\n");
	freeList(list);
	printList(list);
	puts("");

	return 0;
}

List * createList()
{
	List * list;
	list = (List *)malloc(sizeof(List));

	list->head = NULL;
	
	return list;
}

void freeList(List * list)
{
	while(list->head != NULL)
	{
		Node * temp = list->head;
		list->head = list->head->next;

		free(temp);
	}
}

int isEmpty(List * list)
{
	return list->head == NULL ? 1 : 0;
}

void printList(List * list)
{
	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		printf("%s\n", temp->data);
	}
}

void insertFront(List * list, char * str)
{
	Node * node = (Node *)malloc(sizeof(Node));
	strcpy(node->data, str);

	if(isEmpty(list)) 
	{
		list->head = node;
		return;
	}

	node->next = list->head;
	list->head = node;
}

void insertRear(List * list, char * str)
{
	Node * node = (Node *)malloc(sizeof(Node));
	strcpy(node->data, str);
	node->next = NULL;

	if(isEmpty(list))
	{
		list->head = node;
		return;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(temp->next == NULL) 
		{
			temp->next = node;
			return;
		}
	}
}

void insertByIndex(List * list, char * str, int index)
{
	if(index == 1)
	{
		insertFront(list, str);
		return ;
	}

	int count = 0;

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(++count == index - 1)
		{
			Node * node = (Node *)malloc(sizeof(Node));

			strcpy(node->data, str);
			node->next = temp->next;
			temp->next = node;
			
			return ;
		}
	}
	printf("범위를 벗어났습니다.\n마지막에 데이터를 추가합니다.\n");
	insertRear(list, str);
}

void removeFront(List * list)
{
	if(isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	Node * temp = list->head;
	list->head = list->head->next;

	free(temp);
	temp = NULL;
}

void removeRear(List * list)
{
	if(isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(temp->next->next == NULL)
		{
			Node * node = temp->next;
			free(node);
			node = NULL;
			temp->next = NULL;
			return ;
		}
	}
}

void removeByIndex(List * list, int index)
{
	if(isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	int count = 0;

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(++count == index - 1)
		{
			Node * node = temp->next;
			temp->next = temp->next->next;

			free(node);

			return ;
		}
	}
	printf("범위를 벗어났습니다.\n마지막 데이터를 삭제합니다.\n");
	removeRear(list);
}

void searchData(List * list, char * str)
{
	if(isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}
	
	int count = 0;

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		count++;

		if(strcmp(temp->data, str) == 0)
		{
			printf("%d번째에 데이터 \"%s\"가 존재합니다.\n", count, temp->data);
			return ;
		}
	}
	printf("데이터가 존재하지 않습니다.\n");
}

void searchByIndex(List * list, int index)
{
	if(isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	int count = 0;

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(++count == index)
		{
			printf("%d번째 데이터는 \"%s\" 입니다.\n", index, temp->data);
			return ;
		}
	}

	printf("범위를 벗어났습니다.\n");
}
