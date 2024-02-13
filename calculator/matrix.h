#pragma once

#define SIZEOF2X2 2
#define SIZEOF3X3 3

typedef enum MATRIXSIZE
{
	two_X_two = 1,
	three_X_three, // 2
	quit // 3
}MATRIXSIZE;

int calcMatrix(void);
int getMenuMatrix(int* matrixSize);
int calc2x2Matrix(int(*c2x2Matrix)[2], ll* res);
int get2x2MatrixElement(int(*c2x2Matrix)[2], int size);
int get3x3MatrixElement(int(*c2x2Matrix)[3], int size);
void print2DArrayExample(char(*arr)[4]);
void print3DArrayExample(char(*arr)[5]);
void print2DArray(int(*arr)[2]);
void print3DArray(int(*arr)[3]);
int matrixClear(int(*c2x2Matrix)[2], int(*c3x3Matrix)[3]);
int inputIntForMatrixMenu(void);
int inputIntForMatrix(void);