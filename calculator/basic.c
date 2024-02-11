#include "basic.h"

#include <stdio.h>

void arrayClear(char* arr, int size) //reset array to NULL
{
	int i;

	for (i = 0; i < size - 1; i++)
	{
		arr[i] = 0;
	}

	return;
}

void buffClear(void) //clear stdin buffer
{
	while (getchar() != '\n') { ; }
	return;
}