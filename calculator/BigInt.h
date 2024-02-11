#pragma once

int calcBigInt(void);
int getBigInt(char(*bigInt)[102], int size, int* numLen);
int addBigInt(char(*bigInt)[102], ll* saveAddNum, int* numLen);
int printRes(ll* saveAddNum, int size);
void resetTemp(char* temp, int size);
int resetBigInt(char(*BigInt)[102], int size);