#include "basic.h"

#include <stdio.h>
#include <stdlib.h>

void charArrayClear(char* arr, int size) //reset array to NULL
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	return;
}

void intArrayClear(int* arr, int size) //reset array to 0
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	return;
}

void llArrayClear(ll* arr, int size) //reset array to 0
{
	int i;

	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	return;
}

void arraySetZero(char* arr, int size) //reset char array to '0'
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
	char* msg = "1. 다시 계산하기\n2. 이전 메뉴로 나가기\n";

	for (;;)
	{
		for (;;)
		{
			printf("\n%s", msg);
			scanf("%d", &num);

			if (getchar() != '\n')
			{
				printf("다시 입력해주십시오.\n");
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
			printf("다시 입력해주십시오.\n");
		}
	}
}