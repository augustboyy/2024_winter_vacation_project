#pragma once

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0])) // macro for counting array room

typedef long long ll;

int calcBigInt(void);
int getBigInt(char(*bigInt)[102], int size, int* numLen);
int addBigInt(char(*bigInt)[102], ll* saveAddNum, int* numLen);
int printRes(ll* saveAddNum, int size);
void resetTemp(char* temp, int size);
int resetArray(char(*arr)[102], int size);
void arrayClear(char* arr, int size);
void buffClear(void);