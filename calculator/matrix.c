#pragma warning(disable: 4996) // for MSVC

#include "basic.h"
#include "matrix.h"

#include <stdio.h>
#include <windows.h> // for system("cls")

int calcMatrix(void)
{
	int matrixSize;
	int c2x2Matrix[2][2];
	int c3x3Matrix[3][3];
	ll res;
	int check, menu;

	for (;;)
	{
		check = 1;
		check = matrixClear(c2x2Matrix, c3x3Matrix);
		res = 0;

		if (check == 0)
		{
			check = 1;
			check = getMenuMatrix(&matrixSize);
		}

		else
		{
			goto ABNORMAL_BEHAVIER;
		}

		if (check == 0)
		{
			switch (matrixSize)
			{
				case two_X_two:
					check = calc2x2Matrix(c2x2Matrix, &res);

					if (check == 0)
					{
						goto RECALC;
					}

					else
					{
						goto ABNORMAL_BEHAVIER;
					}

				case three_X_three:
					break;

				case quit:
					system(CLEAR);
					return 0;

				default:
					break;
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

int getMenuMatrix(int* matrixSize)
{
	*matrixSize = inputIntForMatrixMenu();

	return 0; // if there is no error, return 0
}

int calc2x2Matrix(int(*c2x2Matrix)[2], ll*res)
{
	int check, menu;
	char* Example[][4] = {
		{"|", "a1", "a1", "|"},
		{"|", "b1", "b2", "|"},
	};

	for (;;)
	{
		check = 1;
		system(CLEAR);
		printf("2x2 행렬을 계산합니다.\n");
		print2DArrayExample(Example);

		check = get2x2MatrixElement(c2x2Matrix, SIZEOF2X2);
		print2DArray(c2x2Matrix);

		if(check == 0)
		{
			*res = c2x2Matrix[0][0] * c2x2Matrix[1][1] - c2x2Matrix[0][1] * c2x2Matrix[1][0];
			printf("결과는 %lld입니다.\n", *res);

			menu = inputIntForFunctionMenu();

			if (menu == 1)
			{
				system(CLEAR);
				goto RECALC;
			}

			else
			{
				system(CLEAR);
				return 0; // if there is no error, return 0
			}
		}

		else
		{
			return 1; // if there is an error, return 1
		}

		RECALC:
			;
	}
}

int get2x2MatrixElement(int(*c2x2Matrix)[2], int size)
{
	int i, j;

	for (j = 0; j < SIZEOF2X2; j++)
	{
		for (i = 0; i < SIZEOF2X2; i++)
		{
			if (j == 0)
			{
				printf("a%d = ", i + 1);
				c2x2Matrix[j][i] = inputIntForMatrix(j, i);
			}

			else
			{
				printf("b%d = ", i + 1);
				c2x2Matrix[j][i] = inputIntForMatrix(j, i);
			}
		}
	}

	return 0; // if there is no error, return 0
}

int get3x3MatrixElement(int(*c2x2Matrix)[3], int size)
{
	int i, j;

	for (j = 0; j < SIZEOF3X3; j++)
	{
		for (i = 0; i < SIZEOF3X3; i++)
		{
			if (j == 0)
			{
				printf("a%d = ", i + 1);
				c2x2Matrix[j][i] = inputIntForMatrix(j, i);
			}

			else if (j == 1)
			{
				printf("b%d = ", i + 1);
				c2x2Matrix[j][i] = inputIntForMatrix(j, i);
			}

			else
			{
				printf("c%d = ", i + 1);
				c2x2Matrix[j][i] = inputIntForMatrix(j, i);
			}
		}
	}

	return 0; // if there is no error, return 0
}

void print2DArrayExample(char*(*arr)[4]) 
{
	int i, j;

	for (j = 0; j < 2; j++) 
	{
		for (i = 0; i < 4; i++) 
		{
			printf("%s ", arr[j][i]);
		}
		putchar('\n');
	}

	return;
}

void print3DArrayExample(char*(*arr)[5])
{
	int i, j;

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 5; i++)
		{
			printf("%s ", arr[j][i]);
		}
		putchar('\n');
	}

	return;
}

void print2DArray(int(*arr)[2])
{
	int i, j;

	for (j = 0; j < 2; j++)
	{
		printf("| ");
		for (i = 0; i < 2; i++)
		{
			printf("%d ", arr[j][i]);
		}
		putchar('|');
		putchar('\n');
	}

	return;
}

void print3DArray(int(*arr)[3])
{
	int i, j;

	for (j = 0; j < 3; j++)
	{
		printf("| ");
		for (i = 0; i < 3; i++)
		{
			printf("%d ", arr[j][i]);
		}
		putchar('|');
		putchar('\n');
	}

	return;
}

int matrixClear(int(*c2x2Matrix)[2], int(*c3x3Matrix)[3])
{
	int i;

	for (i = 0; i < SIZEOF2X2; i++)
	{
		intArrayClear(c2x2Matrix[i], SIZEOF2X2);
	}

	for (i = 0; i < SIZEOF3X3; i++)
	{
		intArrayClear(c3x3Matrix[i], SIZEOF3X3);
	}

	return 0; // if there is no error, return 0
}

int inputIntForMatrixMenu(void)
{
	int num = 0;
	char* msg = "1. 2x2\n2. 3x3\n3. QUIT\n";

	for (;;)
	{
		for (;;)
		{
			printf("%s", msg);
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

		if (num <= 3 && num >= 1) // number 1 ~ 3 are allowed
		{
			return num;
		}

		else
		{
			printf("다시 입력해주십시오.\n");
		}
	}
}

int inputIntForMatrix(int j, int i)
{
	int num = 0;

	for (;;)
	{
		scanf("%d", &num);

		if (getchar() != '\n')
		{
			while (getchar() != '\n')
			{
				;
			}

			printf("잘못된 입력입니다.\n");
			if(j == 0)
			{
				printf("a%d = ", i + 1);
			}

			else if (j == 1)
			{
				printf("b%d = ", i + 1);
			}

			else
			{
				printf("c%d = ", i + 1);
			}
		}

		else
		{
			break;
		}
	}

	return num;
}