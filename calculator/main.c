#pragma once

#pragma warning (disable : 4996) // for MSVC

#include <stdio.h>
#include "menu.h" // declaration of menu enum

#define SIZE(arr) sizeof(arr) / sizeof(arr[0]); // macro for counting array room

void menuDisplay(char** menu, size_t menuCnt);
int inputInt(void);

int main(void)
{
	int menuNum; // variable for save input menu number
	char* menu[] = { "1. BigInt", "6. QUIT" }; // array which is pointing menu string
	size_t menuCnt = SIZE(menu); // variable for save menu count

	for (;;)
	{
		menuDisplay(menu, menuCnt); // function call for display menu
		menuNum = inputInt(); // function call for input menu number

		switch (menuNum) // execute menu number
		{
			case BigInt:
				break;

			case QUIT:
				goto END;
			default:
				break;
		}
	}

	END :
	return 0;
}

void menuDisplay(char** menu, size_t menuCnt)
{
	int i;

	for (i = 0; i < menuCnt; i++)
	{
		printf("%s\n", *(menu + i));
	}

	return;
}

int inputInt(void)
{
	int num = 0;

	for (;;)
	{
		for (;;)
		{
			scanf("%d", &num);

			if (getchar() != '\n')
			{
				while (getchar() != '\n') { ; }
			}

			else 
			{
				break;
			}
		}

		if (num <= 6 && num >= 1) // 1 ~ 6 사이의 숫자만 입력받게 만들기
		{ 
			return num;
			break;
		}

		else 
		{
			printf("다시 입력해주십시오.\n");
		}
	}
}