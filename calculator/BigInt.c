#pragma once

#include "BigInt.h"

#include <stdio.h>

int calcBigInt(void) // 예외처리 해야함
{
	char bigInt[2][102] = { { 0, }, { 0, } }; // bigInt[0] : first big number, bigInt[1] : second big number
	char res[103] = { 0, };
	size_t numLen[2]; // numLen[0] : length of first big number, numLen[1] : length of second big number

	int check = 1;

	check = getBigInt(bigInt, numLen);

	if (check == 0)
	{
		check = addBigInt(bigInt, res, numLen);
	}

	else
	{
		return 1;
	}
}

int getBigInt(char(* bigInt)[102], size_t* numLen)
{
	int i, j = 0;
	int check = 0; // if input is not number, check is 1

	for (;;)
	{
		check = 0; // initialize check

		switch (j)
		{
		case 0:
			printf("첫번째 큰 수를 입력해주십시오.\n");
			break;
		case 1:
			printf("두번째 큰 수를 입력해주십시오.\n");
			break;
		default:
			break;
		}

		for (i = 0; (bigInt[j][i] = getchar()) != '\n'; i++) // get character until enter / for this loop, stdin buffer is always cleared
		{
			if((bigInt[j][i] < '0') || (bigInt[j][i] > '9')) // if input is not number, print exception message and clear buffer
			{
				printf("숫자만 입력해주십시오.\n");
				buffClear();
				arrayClear(bigInt[j], SIZE(bigInt[j]));
				check = 1; // exception check
				break;
			}

			if (i > 100) // prevent overflow
			{
				printf("입력한 수가 너무 큽니다!\n");
				buffClear();
				arrayClear(bigInt[j], SIZE(bigInt[j]));
				check = 1; // exception check
				break;
			}
		}

		if (check == 0) // if input is number
		{
			bigInt[j][i] = 0; // last of array is newline, so change it to null
			numLen[j] = i; // save length of bigInt
			j++; // to get next big number
		}

		if(j == 2) // if get two big number, break loop
		{
			/*for debuging*/ printf("첫번째 큰 수 : %s\n두번째 큰 수 : %s\n", bigInt[0], bigInt[1]);
			while (j) // end of this loop, j is 0
			{
				j--;
				arrayClear(bigInt[j], SIZE(bigInt[j])); // clear bigInt array to use next time
			}
			break;
		}
	}

	return 0; // if there is no error, return 0
}

int addBigInt(char(*bigInt)[102], char* res, size_t* numLen)
{

}

void arrayClear(char* arr, size_t size) //reset array to 0
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