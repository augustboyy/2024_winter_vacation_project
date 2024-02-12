#pragma once

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0])) // macro for counting array room

#define CLEAR "cls" // macro for windows shell clear

typedef long long ll;

void arrayClear(char* arr, int size);
void arraySetZero(char* arr, int size);
void buffClear(void);
void* myAlloc(int size, int elemSize);
void myFree(void* ptr);
int inputIntForFunctionMenu(void);