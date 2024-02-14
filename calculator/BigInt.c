#include "basic.h"
#include "BigInt.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // for system("cls")

int calcBigInt(void)
{
	char bigInt[2][102] = { { 0, }, { 0, } }; // bigInt[0] : first big number, bigInt[1] : second big number
	ll saveAddNum[6] = { 0, };
	int numLen[2]; // numLen[0] : length of first big number, numLen[1] : length of second big number
	char* emptyDigit[6] = { "", "", "", "", "", "" }; // for displaying empty digit
	int check, menu, i;

	for (;;)
	{
		check = 1;
		i = 0;
		check = resetEmptyDigit(emptyDigit, SIZE(emptyDigit)); // reset emptyDigit array for using next time

		if (check == 0)
		{
			check = 1;
		}

		else
		{
			goto ABNORMAL_BEHAVIER;
		}

		check = getBigInt(bigInt, SIZE(bigInt[0]), numLen);

		if (check == 0)
		{
			check = 1;
			check = addBigInt(bigInt, saveAddNum, numLen, emptyDigit);

			if (check == 0)
			{
				check = 1;
				check = printResBigInt(saveAddNum, SIZE(saveAddNum), emptyDigit);

				if (check == 0)
				{
					resetBigInt(bigInt, SIZE(bigInt[0])); // reset bigInt array for using next time
					while (emptyDigit[5 - i] != "") // free dynamic memory
					{
						myFree(emptyDigit[5 - i]);
						i++;

						if (i == 5)
						{
							break;
						}
					}

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
				charArrayClear(bigInt[j], size);
				check = 1; // exception check
				break;
			}

			if (i > 100) // prevent overflow
			{
				printf("입력한 수가 너무 큽니다!\n");
				buffClear();
				charArrayClear(bigInt[j], size);
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
			break;
		}
	}

	return 0; // if there is no error, return 0
}

int addBigInt(char(*bigInt)[102], ll* saveAddNum, int* numLen, char** emptyDigit)
{
	ll divNum[][6] = { { 0, }, { 0, } };
	char temp[19];
	int tempDigit;
	int unit[2], tempLen;
	int unitBig;
	int i, j, k;

	for (j = 0; j < 2; j++)
	{
		unit[j] = (numLen[j] / (SIZE(temp) - 1)) + 1; // calculate how many times to divide big number
		tempLen = numLen[j]; // save length of big number

		for (i = 0; i < unit[j]; i++) // loop unit times
		{
			resetTempBigInt(temp, SIZE(temp) - 1); // array temp is null now

			if (tempLen >= 18) // division of Big is not the biggest one
			{
				for (k = 1; k <= SIZE(temp) - 1; k++) // SIZE(temp) - 1 is 18
				{
					temp[SIZE(temp) - 1 - k] = bigInt[j][tempLen - k];
				}

				tempLen -= 18;
			}

			else // division of Big is the biggest one
			{
				for (k = 1; k <= tempLen; k++)
				{
					temp[SIZE(temp) - 1 - k] = bigInt[j][tempLen - k];
				}
			}

			divNum[j][SIZE(divNum[j]) - 1 - i] = atoll(temp); // make division of BigInt(char type) into long long type
		}

	}

	unit[0] > unit[1] ? (unitBig = unit[0]) : (unitBig = unit[1]); // below loop must be done bigier unit times

	for (i = 0; i < unitBig; i++) // loop unit times
	{
		saveAddNum[SIZE(divNum[0]) - 1 - i] += divNum[0][SIZE(divNum[0]) - 1 - i] + divNum[1][SIZE(divNum[0]) - 1 - i]; // add arithmatic

		if (unitBig != 1) // BigInt is bigger than 18 digits
		{
			if (i < unitBig - 1) // except the highest unit
			{
				tempDigit = digitCnt(&saveAddNum[SIZE(divNum[0]) - 1 - i]);

				if (tempDigit == 19) // if saveAddNum is bigger than n * 10^17 (18 digits), manipulate the value
				{
					saveAddNum[SIZE(divNum[0]) - 1 - (i + 1)]++;
					saveAddNum[SIZE(divNum[0]) - 1 - i] -= 1000000000000000000; // (1 * 10^18) when tempDigit == 19, 19 digit's number is always 1
					tempDigit = digitCnt(&saveAddNum[SIZE(divNum[0]) - 1 - i]);
				}

				if (tempDigit < 18) // if division is smaller than 1 *10^17 make 0 array to supplement empty digits
				{
					tempDigit = 18 - tempDigit;
					emptyDigit[SIZE(divNum[0]) - 1 - i] = (char*)myAlloc(tempDigit + 1, sizeof(char));

					if (emptyDigit[SIZE(divNum[0]) - 1 - i] == NULL) // if dynamic allocation is failled
					{
						return 1;
					}

					arraySetZero(emptyDigit[SIZE(divNum[0]) - 1 - i], tempDigit);
					*(emptyDigit[SIZE(divNum[0]) - 1 - i] + tempDigit) = 0; // for %s
				}
			}
		}
	}

	return 0; // if there is no error, return 0
}

int printResBigInt(ll* saveAddNum, int size, char** emptyDigit)
{
	int i, cnt = 0;

	printf("결과 = ");

	for (i = 0; i < size; i++)
	{
		if (saveAddNum[i] == 0) // if there is no value do not print anything
		{
			printf("%s", emptyDigit[i]);
		}

		else
		{
			printf("%s", emptyDigit[i]);
			printf("%lld", saveAddNum[i]);
			cnt = 1;
		}
	}

	if (cnt == 0) // if result is 0
	{
		putchar('0');
	}
	putchar('\n');

	for (i = 0; i < size; i++) // initialize saveAddNum array
	{
		saveAddNum[i] = 0;
	}

	return 0;
}

void resetTempBigInt(char* temp, int size)
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
		charArrayClear(BigInt[j], size);
	}

	return 0; // if there is no error, return 0
}

int resetEmptyDigit(char** emptyDigit, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		emptyDigit[i] = "";
	}

	return 0; // if there is no error, return 0
}

int digitCnt(const ll* saveAddNum) // count digits
{
	int digit = 1;
	ll n = 1, i = 10;

	for (;;)
	{
		n = *saveAddNum / i;

		if (n == 0)
		{
			break;
		}

		else
		{
			digit++;
			i *= 10;
		}
	}

	return digit;
}