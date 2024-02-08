#include "BigInt.h"

#pragma once

#include <stdio.h>

int calcBigInt(void) // 예외처리 해야함
{
	getBigInt();
	return 0;
}

int getBigInt(void)
{
	char bigInt[2][102] = { { 0, }, { 0, } }; // bigInt[0] : first big number, bigInt[1] : second big number
	char res[103] = { 0, };

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
				arrayClear(bigInt[j]);
				check = 1; // exception check
				break;
			}

			if(i > 101) // 버퍼 오버플로우 방지 코드 작성해야함
		}

		if (check == 0) // if input is number
		{
			bigInt[j][i] = 0; // last of array is newline, so change it to null
			j++; // to get next big number
		}

		if(j == 2) // if get two big number, break loop
		{
			printf("첫번째 큰 수 : %s\n두번째 큰 수 : %s\n", bigInt[0], bigInt[1]);
			while (j) // end of this loop, j is 0
			{
				j--;
				arrayClear(bigInt[j]); // clear bigInt array to use next time
			}
			break;
		}
	}

	return 0;
}

void arrayClear(char* arr) //reset array to 0
{
	int i;

	for (i = 0; i < 101; i++)
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