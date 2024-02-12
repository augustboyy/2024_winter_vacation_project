#pragma warning(disable: 4996) // for MSVC
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

void* myAlloc (int size, int elemSize) // dynamic allocation with error check
{
	void* arr = NULL;

	arr = malloc(size * elemSize);

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

void myFree(void* ptr) // avoid dangling pointer
{
	free(ptr);
	ptr = NULL;
}

int inputIntForFunctionMenu(void)
{
	int num = 0;
	char* msg = "1. �ٽ� ����ϱ�\n2. ���� �޴�\n";

	for (;;)
	{
		for (;;)
		{
			printf("\n%s", msg);
			scanf("%d", &num);

			if (getchar() != '\n')
			{
				printf("�ٽ� �Է����ֽʽÿ�.\n");
				buffClear();
			}

			else
			{
				break;
			}
		}

		if (num <= 2 && num >= 1) // number 1 ~ 2 are allowed
		{
			return num;
		}

		else
		{
			printf("�ٽ� �Է����ֽʽÿ�.\n");
		}
	}
}