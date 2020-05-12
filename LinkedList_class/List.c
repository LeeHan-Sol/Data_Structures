#include "List.h"

List * createList()
{
	List * temp = (List *)malloc(sizeof(List));

	temp->init = initList;
	temp->init(temp);

	return temp;
}

void initList(List * list)
{
	list->head = NULL;
	list->tail = NULL;

	list->free = freeList;

	list->isEmpty = isEmpty;
	list->pushFront = pushFront;
	list->pushRear = pushRear;
	list->pushByIndex = pushByIndex;
	list->pushAfterData = pushAfterData;
	list->popFront = popFront;
	list->popRear = popRear;
	list->popByIndex = popByIndex;
	list->popData = popData;

	list->searchByIndex = searchByIndex;
	list->searchRear = searchRear;
	list->searchData = searchData;
	list->size = size;
	list->display = displayList;
	list->rDisplay = rDisplayList;
	list->displayFirstAndLast = displayListFirstAndLast;
}

void freeList(List * list)
{
	while(list->head != NULL)
	{
		Node * temp = list->head;
		list->head = list->head->next;
		free(temp);
		temp = NULL;
	}
	list->head = list->tail = NULL;
}

int isEmpty(List * list)
{
	return list->head == NULL ? 1 : 0;
}

void pushFront(List * list, char * data)
{
	Node * node = createNode(data);

	if(list->head == NULL)
	{
		list->head = list->tail = node;
		return ;
	}

	list->head->prev = node;
	node->next = list->head;
	list->head = node;
}

void pushRear(List * list, char * data)
{
	Node * node = createNode(data);

	if(list->head == NULL)
	{
		list->head = list->tail = node;
		return ;
	}

	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
}

void pushByIndex(List * list, char * data, int index)
{
	int count = 0;

	if(list->head == NULL || index == 1 || index == 0)
	{
		list->pushFront(list, data);
		return ;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(++count == index)
		{
			Node * node = createNode(data);

			node->prev = temp->prev;
			node->next = temp;
			node->prev->next = node;
			temp->prev = node;

			return ;
		}
	}

	printf("범위를 벗어났습니다.\n");
	printf("list의 길이는 %d입니다.\n", list->size(list));
	printf("마지막에 자료를 추가합니다.\n");

	list->pushRear(list, data);
}

int pushAfterData(List * list, char * search, char * data)
{
	if(list->isEmpty(list))
	{
		printf("list가 비었습니다.\n");
		return 0;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(strcmp(temp->data, search) == 0)
		{
			Node * node = createNode(data);

			node->next = temp->next;
			node->prev = temp;

			temp->next = node;
			if(node->next != NULL)
				node->next->prev = node;
			
			return 1;
		}
	}

	printf("찾는 데이터(%s)가 존재하지 않습니다.\n", search);
	
	return 0;
}

void popFront(List * list)
{
	if(list->isEmpty(list))
	{
		return ;
	}
	else
	{
		Node * temp = list->head;

		list->head = list->head->next;
		
		if(list->head != NULL)
			list->head->prev = NULL;

		temp->free(temp);
		temp = NULL;
	}
}

void popRear(List * list)
{
	if(list->isEmpty(list))
	{
		return ;
	}
	else
	{
		Node * node = list->tail;

		if(list->head == list->tail)
		{
			list->head = list->tail = NULL;
			free(node);
			return ;
		}

		list->tail = list->tail->prev;
		list->tail->next = NULL;

		free(node);
		node = NULL;
	}
}

void popByIndex(List * list, int index)
{
	int count = 0;
	
	if(list->head == NULL || index == 0 || index == 1)
	{
		list->popFront(list);
		return ;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(++count == index)
		{
			Node * node = temp;
			
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			free(node);
			node = NULL;

			return;
		}
	}

	printf("범위를 벗어났습니다.\n");
	printf("list의 길이는 %d입니다.\n", list->size(list));
}

void popData(List * list, char * data)
{
	if(list->isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(strcmp(temp->data, data) == 0)
		{
			if(temp->prev == NULL && temp->next == NULL)
			{
				list->head = list->tail = NULL;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}

			free(temp);
			temp = NULL;
			
			return ;
		}
	}
	printf("자료가 존재하지 않습니다.\n");
}

void searchByIndex(List * list, int index)
{
	int count = 0;
	
	if(list->isEmpty(list))
	{
		printf("list가 비었습니다.\n");
		return ;
	}
	
	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(++count == index)
		{
			if(index == 0 || index == 1)
				printf("첫 번째 데이터 : %s\n", temp->data);
			else
				printf("%4d 번째의 데이터 : %s\n", index, temp->data);
			return ;
		}
	}
	printf("%d는 범위를 벗어났습니다.\n", index);
	printf("list의 길이는 %d입니다.\n", list->size(list));
}

void searchRear(List * list)
{
	if(list->isEmpty(list))
	{
		printf("list가 비었습니다.\n");
		return ;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		if(temp->next == NULL)
		{
			printf("마지막 데이터 : %s\n", temp->data);
		}
	}
}

void searchData(List * list, char * data)
{
	int count = 0;

	if(list->isEmpty(list))
	{
		printf("list가 비었습니다.\n");
		return ;
	}

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		count++;
		if(strcmp(temp->data, data) == 0)
		{
			printf("%s는 %d 번째에 데이터가 존재합니다.\n", data, count);
			return ;
		}
	}
	printf("%s를 찾을 수 없습니다.\n", data);
}

int size(List * list)
{
	if(list->isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return 0;
	}

	int count = 0;

	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		++count;
	}
	return count;
}

void displayList(List * list)
{
	printf("List 항목\n");

	if(list->isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}
	
	for(Node * temp = list->head; temp != NULL; temp = temp->next)
	{
		temp->display(temp);
	}
}

void rDisplayList(List * list)
{
	printf("List 항목(역순)\n");

	if(list->isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	for(Node * temp = list->tail; temp != NULL; temp = temp->prev)
	{
		temp->display(temp);
	}
}

void displayListFirstAndLast(List * list)
{
	if(list->isEmpty(list))
	{
		printf("list->head, tail : [{%p}, {%p}]\n", list->head, list->tail);
		return ;
	}

	printf("list->head, tail : [{%s : %p}, {%s : %p}]\n", list->head->data, list->head, list->tail->data, list->tail);
}
