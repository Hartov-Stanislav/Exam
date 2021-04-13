#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ListElement {
	int value;
	struct ListElement* next;
	struct ListElement* previous;
} ListElement;

typedef struct List {
	ListElement* head;
	ListElement* tail;
} List;

Position getFirst(List* list)
{
	return (list == NULL) ? NULL : list->head;
}

Position getLast(List* list)
{
	return (list == NULL) ? NULL : list->tail;
}

Position nextItem(Position position)
{
	return position->next;
}

Position getPreviousItem(Position position)
{
	return position->previous;
}

bool isEnd(Position position)
{
	return position == NULL;
}

int getValue(Position position)
{
	return position->value;
}

bool isEmpty(List* list)
{
	return (list == NULL || list->head == NULL);
}

List* makeList(void)
{
	return calloc(1, sizeof(List));
}

void addItem(List* list, const int value)
{
	if (list == NULL)
	{
		return;
	}

	ListElement* newElement = calloc(1, sizeof(ListElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	newElement->next = NULL;
	newElement->previous = list->tail;
	if (isEmpty(list))
	{
		list->head = newElement;
		list->tail = newElement;
		return;
	}
	list->tail->next = newElement;
	list->tail = newElement;
}

bool removeHeadElement(List* list)
{
	if (isEmpty(list))
	{
		return true;
	}

	ListElement* pointer = list->head;
	list->head = list->head->next;
	if (list->head != NULL)
	{
		list->head->previous = NULL;
	}
	if (pointer == list->tail)
	{
		list->tail = NULL;
	}
	free(pointer);
	return false;
}

void freeList(List** list)
{
	while (!isEmpty(*list))
	{
		removeHeadElement(*list);
	}
	free(*list);
	*list = NULL;
}

void printList(List *list)
{
	if (isEmpty(list))
	{
		printf("List is empty\n");
		return;
	}
	ListElement* pointer = list->head;
	while (pointer != NULL)
	{
		printf("%i ", pointer->value);
		pointer = pointer->next;
	}
}
