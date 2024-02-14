#pragma once

int outerProduct(void);
int getVetctor(int(*vector)[3]);
void initVector(int(*vector)[3]);
void initTemp2x2Matrix(int(*temp2x2Matrix)[2][2]);
int inputIntForVector(int* arr, int menu);
int calcOuterProduct(int(*vector)[3], int(*temp2x2Matrix)[2][2], ll* resVector);
int putResVector(int(*vector)[3], ll* resVector);
void div3x3Vector(const int(*vector)[3], int(*temp2x2Matrix)[2][2]);