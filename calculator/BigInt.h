#pragma once

#define SIZE(arr) sizeof(arr) / sizeof(arr[0]) // macro for counting array room

typedef long long ll;

int calcBigInt(void);
int getBigInt(char(*bigInt)[102],size_t* numLen);
int addBigInt(char(*bigInt)[102], char* res, size_t* numLen);
void arrayClear(char* arr, size_t size);
void buffClear(void);