#include "TestList.h"
#include "List.h"
#include <stdbool.h>
#include <locale.h>

bool testAddItem(void)
{
	List *list = makeList();
	for (int i = 0; i < 10; i++)
	{
		addItem(list, i);
	}

	int temp = 0;
	bool result = true;
	Position position = getFirst(list);
	while (!isEnd(position))
	{
		int current = getValue(position);
		result &= current == temp;
		temp++;
		position = nextItem(position);
	}

	freeList(&list);
	return result;
}

bool testRemove(void)
{
	List* list = makeList();
	for (int i = 0; i < 10; i++)
	{
		addItem(list, i);
	}

	bool result = true;
	for (int i = 0; i < 10; i++)
	{
		result &= !removeHeadElement(list);
	}

	freeList(&list);
	return result;
}