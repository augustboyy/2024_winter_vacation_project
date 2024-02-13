#pragma warning (disable : 4996) // for MSVC

#include <stdio.h>
#include <windows.h> // for system("cls")

#include "basic.h"
#include "menu.h" // declaration of menu enum
#include "BigInt.h" // declaration of BigInt function
#include "base_conversion.h" // dedeclaration of base_conversion function

void menuDisplay(char** menu, int menuCnt);
int inputInt(char** menu, int menuCnt);
void printWarningMsg(char** menu, int menuCnt);

int main(void)
{
	int menuNum; // variable for save input menu number
	char* menu[] = { "1. BigInt", "2. base conversion", "5. QUIT" }; // array which is pointing menu string
	int menuCnt = SIZE(menu); // variable for save menu count
	int check;

	for (;;)
	{
		check = 1;
		menuDisplay(menu, menuCnt); // function call for display menu
		menuNum = inputInt(menu, menuCnt); // function call for input menu number
		system(CLEAR);

		switch (menuNum) // execute menu number
		{
			case BigInt:
				check = calcBigInt(); // function call for BigInt

				if (check == 0) //error check, if error is not occured break the switch-case
				{
					break;
				}

				else // if error is occured print error message and exit program
				{
					goto PRINT_ERROR;
				}

			case base_conversion:				
				check = baseConversion(); // function call for baseConversion

				if (check == 0) //error check, if error is not occured break the switch-case
				{
					break;
				}

				else // if error is occured print error message and exit program
				{
					goto PRINT_ERROR;
				}

			case matrix:
				check = calcMatrix(); // function call for baseConversion

				if (check == 0) //error check, if error is not occured break the switch-case
				{
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

void menuDisplay(char** menu, int menuCnt)
{
	int i;

	for (i = 0; i < menuCnt; i++)
	{
		printf("%s\n", *(menu + i));
	}

	return;
}

int inputInt(char** menu, int menuCnt)
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

		if (num <= 5 && num >= 1) // number 1 ~ 5 are allowed
		{ 
			return num;
		}

		else 
		{	
			printWarningMsg(menu, menuCnt);
		}
	}
}

void printWarningMsg(char** menu, int menuCnt)
{
	system(CLEAR);
	menuDisplay(menu, menuCnt);
	printf("다시 입력해주십시오.\n");

	return;
}