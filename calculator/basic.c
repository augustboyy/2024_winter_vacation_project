#include "basic.h"

#include <stdio.h>
#include <stdlib.h>

void arrayClear(char* arr, int size) //reset array to NULL
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	return;
}

void arraySetZero(char* arr, int size) //reset array to '0'
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = '0';
	}

	return;
}

void buffClear(void) //clear stdin buffer
{
	while (getchar() != '\n') { ; }
	return;
}

char* myAlloc (int size)
{
	char* arr = NULL;

	arr = (char*)malloc(size * sizeof(char));

	if (arr != NULL)
	{
		return arr;
	}

	else
	{
		printf("Dynamic allocation fail!\n");
		return NULL;
	}
}