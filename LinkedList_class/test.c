#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number = 0;
	char str[128] = "\0";

	scanf("%d", &number);
	fgets(str, 128, stdin);

	printf("number : %d\n", number);
	printf("str : %s\n", str);
}
