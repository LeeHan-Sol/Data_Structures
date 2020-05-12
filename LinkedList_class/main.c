#include "List.h"
/*
int main()
{
	List * list = createList();

	if(list->head != NULL)
		printf("head의 값(주소) : %s (%p)\n", list->head->data, list->head);

	list->pushFront(list, "apple");
	list->pushRear(list, "banana");
	list->pushRear(list, "mango");
	list->pushFront(list, "strawberry");
	list->pushRear(list, "orange");
	list->pushRear(list, "grape");

	printf("list display()\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	printf("list display(역순)\n");
	list->rDisplay(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popFront(list);
	printf("after popFront()\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->pushFront(list, "blueberry");
	printf("after pushFront(blueberry)\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->pushRear(list, "grape");
	printf("after pushRear(grape)\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->pushByIndex(list, "pineapple", 3);
	printf("after pushByIndex(pineapple, 3)\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popByIndex(list, 3);
	printf("after popByIndex(3)\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->searchData(list, "apple");
	printf("\n");

	list->searchData(list, "o");
	printf("\n");

	list->searchByIndex(list, 3);
	printf("\n");

	list->searchByIndex(list, 100);
	printf("\n");

	printf("list display(역순)\n");
	list->rDisplay(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()1\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()2\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()3\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()4\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()5\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()6\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()7\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()8\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	list->popRear(list);
	printf("after popRear()9\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	printf("list->size : %d\n", list->size(list));
	puts("");

	list->free(list);
	printf("after free()\n");
	list->display(list);
	list->displayFirstAndLast(list);
	printf("\n");

	return 0;
}
*/

void printSplit(int);

char * copyStr(char *, char *, int);

void optionShowList(List *);
List * optionCreateList();
void optionSearchNode(List *);
void optionInsertNode(List *);
void optionRemoveNode(List *);

int main()
{
	int option = 0;

	void (*optionFunc)(List *);
	optionFunc = NULL;

	List * list = NULL;

	for(;;)
	{
		printf("1. 리스트 보기\n");
		printf("2. 리스트 생성\n");
		printf("3. 노드 검색\n");
		printf("4. 노드 추가\n");
		printf("5. 노드 삭제\n");
		printf("6. 종료\n");

		printf(" >> ");
		scanf("%d", &option);
		getchar();
		
		if(option == 6)
		{
			printf("프로그램을 종료합니다.\n");
			list->free(list);
			break;
		}

		printSplit(30);

		if(option == 1)
		{
			optionFunc = optionShowList; 
		}
		else if(option == 2)
		{
			if(list != NULL)
			{
				printf("list를 교체합니다.\n");
			}
			list = optionCreateList();
		}
		else if(option == 3)
		{
			optionFunc = optionSearchNode;
		}
		else if(option == 4)
		{
			optionFunc = optionInsertNode;
		}
		else if(option == 5)
		{
			optionFunc = optionRemoveNode;
		}
		else
		{
			printf("다시 선택해주세요.\n");
			continue;
		}

		if(optionFunc != NULL)
		{
			if(list == NULL)
			{
				printf("list를 생성해주세요\n");
			}
			else
			{
				optionFunc(list);
			}
		}

		optionFunc = NULL;
		printSplit(30);
	}
	return 0;
}

void printSplit(int count)
{
	for(int i = 0; i < count; i++)
		printf("-");
	printf("\n");
}

char * copyStr(char * data, char * buffer, int length)
{
	data = (char *)malloc(sizeof(char) * (length));
	memset(data, 0x00, length);
	
	strncpy(data, buffer, length - 1);

	return data;
}

void optionShowList(List * list)
{
	int option = 0;

	if(list != NULL)
	{
		for(;;)
		{
			printf("1. 정방향 list 보기\n");
			printf("2. 역방향 list 보기\n");		
			printf("3. 돌아가기\n");

			printf(" >>");
			scanf("%d", &option);

			if(option == 3)
				return ;

			printSplit(30);

			if(option == 1)
				list->display(list);
			else if(option == 2)
				list->rDisplay(list);
			else
			{
				printf("다시 선택해주세요.\n");
				printSplit(30);
				continue;
			}
			printSplit(30);
		}
	}
	else
	{
		printf("리스트가 존재하지 않습니다.\n");
		printSplit(30);
		return ;
	}
}

List * optionCreateList()
{
	List * newList = createList();
	
	printf("list가 생성되었습니다.\n");
	printf("list : [%p]\n", newList);

	return newList;
}

void optionSearchNode(List * list)
{
	int option = 0;

	if(list->isEmpty(list))
	{
		printf("list가 비어있습니다.\n");
		return ;
	}

	for(;;)
	{
		printf("1. 첫 번째 노드 검색\n");
		printf("2. 마지막 노드 검색\n");
		printf("3. 인덱스로 검색\n");
		printf("4. 데이터로 검색\n");
		printf("5. 돌아가기\n");

		printf(" >> ");
		scanf("%d", &option);
		getchar();

		if(option == 5)
		{
			return ;
		}

		printSplit(30);

		if(option == 1)
		{
			list->searchByIndex(list, 1);
		}
		else if(option == 2)
		{
			list->searchRear(list);
		}
		else if(option == 3)
		{
			int index = 0;
			printf("몇 번째 index를 검색할까요?\n");
			printf(" >> ");
			scanf("%d", &index);
			getchar();

			list->searchByIndex(list, index);
		}
		else if(option == 4)
		{
			char buffer[128];
			int length = 0;

			printf("검색하려는 data를 입력해주세요.\n");
			printf(" >> ");
			fgets(buffer, 128, stdin);
			length = strlen(buffer);
			buffer[length - 1] = 0x00;

			list->searchData(list, buffer);
		}
		else
		{
			printf("엥... 그건 없는 메뉴에요!\n");
			printSplit(30);
			continue;
		}

		printSplit(30);
	}
}

void optionInsertNode(List * list)
{
	int option = 0;
	char * data = NULL;
	char buffer[128];
	int length = 0;
	int flag = 1;

	for(;;)
	{
		printf("1. 첫 번째 노드 추가\n");
		printf("2. 마지막 노드 추가\n");
		printf("3. 인덱스로 추가\n");
		printf("4. 데이터 검색 후 다음으로 추가\n");
		printf("5. 돌아가기\n");

		printf(" >> ");
		scanf("%d", &option);
		getchar(); //scanf를 하고나서 입력 buffer에 '\n'이 남아있어서 다음 fgets를 받지 못하고 넘어가 버리는 경우가 발생. 이러한 상황을 방지하기 위해 scanf를 사용하고 난뒤 getchar()를 수행해 '\n'문자를 입력버퍼에서 제거하도록 한다.

		if(option == 5)
		{
			return ;
		}

		printSplit(30);
		
		printf("추가하려는 데이터 입력\n");
		printf(" >> ");
		fgets(buffer, 128, stdin);
		length = strlen(buffer);

		data = copyStr(data, buffer, length);

		if(option == 1)
		{
			list->pushFront(list, data);
		}
		else if(option == 2)
		{
			list->pushRear(list, data);
		}
		else if(option == 3)
		{
			int index = 0;
			
			printf("몇 번째 index에 추가할까요?\n");
			printf(" >> ");
		
			scanf("%d", &index);
			getchar();

			list->pushByIndex(list, data, index);
		}
		else if(option == 4)
		{
			int lengthOfSearch = 0;
			char search[128];

			printf("검색하려는 데이터를 입력\n");
			printf(" >> ");
			fgets(search, 128, stdin);
			lengthOfSearch = strlen(search);
			search[lengthOfSearch - 1] = 0x00;
				
			flag = list->pushAfterData(list, search, data);
		}
		else
		{
			printf("엥... 그건 없는 메뉴에요!\n");
			printSplit(30);
			continue;
		}

		if(flag)
			printf("list에 자료가 추가되었습니다.\n");
		puts("");
		list->display(list);
		puts("");
		printSplit(30);
	}
}

void optionRemoveNode(List * list)
{
	int option = 0;

	for(;;)
	{
		printf("1. 첫 번째 노드 제거\n");
		printf("2. 마지막 노드 제거\n");
		printf("3. 인덱스로 제거\n");
		printf("4. 데이터로 제거\n");
		printf("5. 돌아가기\n");

		printf(">> ");
		scanf("%d", &option);
		getchar();

		if(option == 5)
		{
			return ;
		}

		printSplit(30);

		if(option == 1)
		{
			list->popFront(list);
		}
		else if(option == 2)
		{
			list->popRear(list);
		}
		else if(option == 3)
		{
			int index = 0;
			printf("몇 번째 index를 제거할까요?\n");
			printf(">> ");
			scanf("%d", &index);
			printSplit(30);
			
			list->popByIndex(list, index); 
		}
		else if(option == 4)
		{
			char buffer[128];
			int length = 0;

			printf("제거할 자료를 입력해주세요.\n");
			fgets(buffer, 128, stdin);
			length = strlen(buffer);
			buffer[length - 1] = 0x00;

			list->popData(list, buffer);
		}
		else
		{
			printf("엥... 그건 없는 메뉴에요!\n");
			printSplit(30);
			continue;
		}

		printf("list에 자료가 제거되었습니다.\n");
		puts("");
		list->display(list);
		puts("");
		printSplit(30);
	}
}
