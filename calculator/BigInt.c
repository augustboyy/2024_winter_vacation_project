#include "basic.h"
#include "BigInt.h"

#include <stdio.h>
#include <stdlib.h>

int calcBigInt(void) // 예외처리 해야함
{
	char bigInt[2][102] = { { 0, }, { 0, } }; // bigInt[0] : first big number, bigInt[1] : second big number
	ll saveAddNum[6] = { 0, };
	int numLen[2]; // numLen[0] : length of first big number, numLen[1] : length of second big number

	for (;;)
	{
		int check = 1;

		check = getBigInt(bigInt, SIZE(bigInt[0]), numLen);

		if (check == 0)
		{
			check = 1;
			check = addBigInt(bigInt, saveAddNum, numLen);

			if (check == 0)
			{
				check = 1;
				check = printRes(saveAddNum, SIZE(saveAddNum));

				if (check == 0)
				{
					resetBigInt(bigInt, SIZE(bigInt[0]));
					return 0;
				}

				else
				{
					goto ERROR;
				}
			}

			else
			{
				goto ERROR;
			}
		}

		else
		{
			goto ERROR;
		}

		ERROR:
			return 1;
	}
}

int getBigInt(char(* bigInt)[102], int size, int* numLen)
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
				arrayClear(bigInt[j], size);
				check = 1; // exception check
				break;
			}

			if (i > 100) // prevent overflow
			{
				printf("입력한 수가 너무 큽니다!\n");
				buffClear();
				arrayClear(bigInt[j], size);
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
			printf("첫번째 큰 수 : %s\n두번째 큰 수 : %s\n", bigInt[0], bigInt[1]);
			break;
		}
	}

	return 0; // if there is no error, return 0
}

int addBigInt(char(*bigInt)[102], ll* saveAddNum, int* numLen)
{
	ll divNum[][6] = { { 0, }, { 0, } };
	char temp[19];
	int unit, tempLen;
	int i, j, k;

	for (j = 0; j < 2; j++)
	{
		resetTemp(temp, SIZE(temp) - 1);

		unit = (numLen[j] / (SIZE(temp) - 1)) + 1;
		tempLen = numLen[j];

		for (i = 0; i < unit; i++)
		{
			resetTemp(temp, SIZE(temp) - 1);

			if (tempLen >= 18)
			{
				for (k = 1; k <= SIZE(temp) - 1; /*== 18*/ k++)
				{
					temp[SIZE(temp) - 1 - k] = bigInt[j][tempLen - k];
				}

				/*printf("%s\n", temp);*/

				tempLen -= 18;
			}

			else
			{
				for (k = 1; k <= tempLen; k++)
				{
					temp[SIZE(temp) - 1 - k] = bigInt[j][tempLen - k];
				}
				//printf("q%s\n", temp);
			}

			divNum[j][SIZE(divNum[j]) - 1 - i] = atoll(temp);
		}

		for (i = 0; i < unit; i++)
		{
			saveAddNum[SIZE(divNum[j]) - 1 - i] = divNum[0][SIZE(divNum[j]) - 1 - i] + divNum[1][SIZE(divNum[j]) - 1 - i];
		}
	}

	return 0;
}

int printRes(ll* saveAddNum, int size)
{
	int i, cnt = 0;

	for (i = 0; i < size; i++)
	{
		if (saveAddNum[i] == 0)
		{
			;
		}

		else
		{
			printf("%lld", saveAddNum[i]);
			cnt = 1;
		}
	}

	if (cnt == 0)
	{
		putchar('0');
	}
	putchar('\n');

	for (i = 0; i < size; i++)
	{
		saveAddNum[i] = 0;
	}

	return 0;
}

void resetTemp(char* temp, int size)
{
	int i;

	for (i = 0; i < size; i++) // initialize temp array '0' to use atoi()
	{
		temp[i] = '0';
	}
	temp[size] = 0; // to use atoi()

	return;
}

int resetBigInt(char(*BigInt)[102], int size)
{
	int j;

	for (j = 0; j < 2; j++)
	{
		arrayClear(BigInt[j], size);
	}

	return 0; // if there is no error, return 0
}

//int inputInt(const char* msg) {
//
//	int num = 0;
//
//	for (;;) {
//
//		printf("%s", msg);
//		scanf("%d", &num);
//
//		if (getchar() != '\n') {
//			while (getchar() != '\n') {
//				;
//			}
//		}
//
//		else {
//			break;
//		}
//	}
//	return num;
//}