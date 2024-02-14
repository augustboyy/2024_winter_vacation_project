#pragma warning (disable : 4996) // for MSVC

#include "basic.h"
#include "base_conversion.h"

#include <stdio.h>
#include <windows.h> // for system("cls")

int baseConversion(void)
{
	int decNum; // biNum, octNum. hexNum will be added
	unsigned int detection;
	char string[33];
	int check, menu;

	for (;;)
	{	
		check = 1; // check variable for error check
		charArrayClear(string, SIZE(string)); // reset string array to NULL
		detection = (unsigned)0x80000000; // 2147483648 in decimal

		check = getDecNum(&decNum);

		if (check == 0)
		{
			check = 1;
			check = convertBase(&decNum, &detection, string);

			if (check == 0)
			{
				check = 1;
				check = printResBase(&decNum, string);

				if (check == 0)
				{
					menu = inputIntForFunctionMenu();

					if (menu == 1)
					{
						system(CLEAR);
						goto RECALC;
					}

					else
					{
						system(CLEAR);
						return 0;
					}
				}

				else
				{
					goto ABNORMAL_BEHAVIER;
				}
			}

			else
			{
				goto ABNORMAL_BEHAVIER;
			}
		}

		else
		{
			goto ABNORMAL_BEHAVIER;
		}

		ABNORMAL_BEHAVIER:
			return 1;

		RECALC:
			;
	}

	return 0; // if there is no error, return 0
}

int getDecNum(int* num)
{
	*num = inputIntForBase("정수를 입력하시오 : ");

	return 0; // if there is no error, return 0
}

int inputIntForBase(const char* msg)
{
	int num = 0;

	for (;;) 
	{
		printf("%s", msg);
		scanf("%d", &num);

		if (getchar() != '\n') 
		{
			while (getchar() != '\n')
			{
				;
			}
			
			printf("잘못된 입력입니다.\n");
		}

		else 
		{
			break;
		}
	}

	return num;
}

int convertBase(const int* decNum, unsigned int* detection, char* string)
{
	int i;
	unsigned int res;

	for (i = 0; i < 32; i++)
	{
		res = *decNum & *detection; // bitwise AND operation AND operation detect bit 1 or 0
		res >>= (31 - i);

		if (res == 0)
		{
			string[i] = '0';
		}

		else
		{
			string[i] = '1';
		}

		*detection >>= 1; // shift right 1 bit to check next bit
	}

	return 0; // if there is no error, return 0
}

int printResBase(int* decNum, char* string)
{
	if (*decNum >= 0)
	{
		printf("2진수 : %s\n", string);
	}

	else
	{
		printf("2진수 (2의 보수) : %s\n", string);
	}

	return 0; // if there is no error, return 0
}