#include "List.h"
#include "TestList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

List* flipList(List* list)
{
	List* newList = makeList();
	Position position = getLast(list);
	while (!isEnd(position))
	{
		addItem(newList, getValue(position));
		position = getPreviousItem(position);
	}
	return newList;
}

void fillList(List** list, int left, int right, int size)
{
	if (*list != NULL)
	{
		freeList(list);
	}
	*list = makeList();
	for (int i = 0; i < size; i++)
	{
		addItem(*list, rand() % (right - left) + left);
	}
}

bool handleCommands(const int code, List** list)
{
	int size = 0;
	int left = 0;
	int right = 0;
	List* oldList = NULL;
	switch (code)
	{
	case 0:
		freeList(list);
		return true;
	case 1:
		printf("Enter size of list and range of its values: ");
		scanf("%d%d%d", &size, &left, &right);
		if (right < left)
		{
			printf("Ivalid range\n");
			break;
		}
		fillList(list, left, right, size);
		break;
	case 2:
		oldList = *list;
		*list = flipList(*list);
		freeList(&oldList);
		break;
	case 3:
		printList(*list);
		printf("\n");
		break;
	default:
		break;
	}
	return false;
}

bool tests(void)
{
	List* firstList = NULL;
	fillList(&firstList, 1, 10, 10);
	List* secondList = flipList(firstList);
	Position firstPointer = getFirst(firstList);
	Position secondPointer = getLast(secondList);
	bool result = true;

	while (!isEnd(firstPointer) && !isEnd(secondPointer))
	{
		result &= (getValue(firstPointer) == getValue(secondPointer));
		firstPointer = nextItem(firstPointer);
		secondPointer = getPreviousItem(secondPointer);
	}

	freeList(&firstList);
	freeList(&secondList);
	return result;
}

int main()
{
	if (!testRemove() || !testAddItem())
	{
		printf("List tests failed");
		return 1;
	}
	printf("List tests succeed\n");
	if (!tests())
	{
		printf("Tests failed");
		return 1;
	}
	printf("Tests succeed\n");
	
	srand(time(NULL));
	printf("Commands:\n");
	printf("0 - exit\n");
	printf("1 - fill list with random numbers\n");
	printf("2 - flip the list\n");
	printf("3 - print the list\n");
	List* list = NULL;
	while (true)
	{
		int code = 0;
		printf("Enter command code: ");
		scanf("%d", &code);
		if (handleCommands(code, &list))
		{
			return 0;
		}
	}

	return 0;
}