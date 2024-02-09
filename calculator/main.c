#pragma once

#pragma warning (disable : 4996) // for MSVC

#include <stdio.h>
#include <windows.h> // for system("cls")

#include "menu.h" // declaration of menu enum
#include "BigInt.h" // declaration of BigInt function

#define SIZE(arr) sizeof(arr) / sizeof(arr[0]) // macro for counting array room

void menuDisplay(char** menu, size_t menuCnt);
int inputInt(char** menu, size_t menuCnt);
void printWarningMsg(char** menu, size_t menuCnt);
void buffClear(void); // defined in BigInt.c

int main(void)
{
	int menuNum; // variable for save input menu number
	char* menu[] = { "1. BigInt", "6. QUIT" }; // array which is pointing menu string
	size_t menuCnt = SIZE(menu); // variable for save menu count
	int check = 1;

	for (;;)
	{
		menuDisplay(menu, menuCnt); // function call for display menu
		menuNum = inputInt(menu, menuCnt); // function call for input menu number
		system("cls");

		switch (menuNum) // execute menu number
		{
			case BigInt:
				check = calcBigInt(); // function call for BigInt

				if (check == 0) //error check
				{
					check = 1;
					break;
				}

				else // if error is occured print error message and exit program
				{
					goto PRINT_ERROR;
				}
			case QUIT:
				goto END;
			default:
				break;
		}
	}

	PRINT_ERROR:
	printf("에러가 발생하였습니다.\n프로그램을 종료합니다.");

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

int inputInt(char** menu, size_t menuCnt)
{
	int num = 0;

	for (;;)
	{
		for (;;)
		{
			scanf("%d", &num);

			if (getchar() != '\n')
			{
				buffClear();
				printWarningMsg(menu, menuCnt);
			}

			else 
			{
				break;
			}
		}

		if (num <= 6 && num >= 1) // number 1 ~ 6 are allowed
		{ 
			return num;
			break;
		}

		else 
		{	
			printWarningMsg(menu, menuCnt);
		}
	}
}

void printWarningMsg(char** menu, size_t menuCnt)
{
	system("cls");
	menuDisplay(menu, menuCnt);
	printf("다시 입력해주십시오.\n");

	return;
}