#pragma warning (disable : 4996) // for MSVC

#include "basic.h"
#include "vector_outerproduct.h"
#include "matrix.h" // for calculate function

#include <stdio.h>
#include <windows.h> // for system("cls")

int outerProduct(void)
{
	int vector[2][3];
	int check, menu;
	ll resVector[3];
	int temp2x2Matrix[3][2][2];
	int i;

	for (;;)
	{
		check = 1;
		initVector(vector);
		llArrayClear(resVector, 3);
		initTemp2x2Matrix(temp2x2Matrix);

		check = getVetctor(vector);

		if (check == 0)
		{
			check = 1;
			check = calcOuterProduct(vector, temp2x2Matrix, resVector);

			if (check == 0)
			{
				check = 1;
				check = putResVector(vector, resVector);

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

		ABNORMAL_BEHAVIER:
			return 1;

		RECALC:
			;
	}
}

int getVetctor(int(*vector)[3])
{
	int i;
	int check;

	for (i = 0; i < 2; i++)
	{
		check = 1;
		check = inputIntForVector(vector[i], i);
	}

	if (check == 0)
	{
		return 0;
	}

	else
	{
		return 1;
	}

}

void initVector(int(*vector)[3])
{
	int i;

	for (i = 0; i < 2; i++)
	{
		intArrayClear(vector[i], 3);
	}

	return;
}

void initTemp2x2Matrix(int(*temp2x2Matrix)[2][2])
{
	int i;

	for (i = 0; i < 3; i++)
	{
		intArrayClear(temp2x2Matrix[i][0], 2);
		intArrayClear(temp2x2Matrix[i][1], 2);
	}

	return;
}

int inputIntForVector(int* arr, int menu)
{
	for (;;)
	{
		if (menu == 0)
		{
			printf("첫번째 벡터를 입력하세요. (각 원소는 , 로 구분합니다.): ");
		}

		else
		{
			printf("두번째 벡터를 입력하세요. (각 원소는 , 로 구분합니다.): ");
		}

		scanf("%d,%d,%d", arr, arr + 1, arr + 2);

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

	return 0;
}

int calcOuterProduct(int(*vector)[3], int(*temp2x2Matrix)[2][2], ll* resVector)
{
	int i;

	div3x3Vector(vector, temp2x2Matrix);

	for (i = 0; i < 3; i++)
	{
		resVector[i] = calculate(temp2x2Matrix[i]);
	}

	return 0;
}

int putResVector(int(*vector)[3], ll* resVector)
{
	system(CLEAR);
	printf("첫번째 벡터 : (%d, %d, %d)\n", vector[0][0], vector[0][1], vector[0][2]);
	printf("두번째 벡터 : (%d, %d, %d)\n", vector[1][0], vector[1][1], vector[1][2]);
	printf("결과 : ");
	printf("(%lld, %lld, %lld)\n", resVector[0], - resVector[1], resVector[2]);

	return 0;
}

void div3x3Vector(const int(*vector)[3], int(*temp2x2Matrix)[2][2])
{
	int i, iter1 = 0, iter2 = 0;

	for (i = 0; i < SIZEOF3X3; i++)
	{
		if (i == 0)
		{
			iter1 = 1;
			iter2 = 2;
		}

		else if (i == 1)
		{
			iter1 = 0;
			iter2 = 2;
		}

		else
		{
			iter1 = 0;
			iter2 = 1;
		}

		temp2x2Matrix[i][0][0] = vector[0][iter1];
		temp2x2Matrix[i][0][1] = vector[0][iter2];
		temp2x2Matrix[i][1][0] = vector[1][iter1];
		temp2x2Matrix[i][1][1] = vector[1][iter2];
	}

	return;
}