#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

__declspec(dllexport) int SquareInt(int param);
__declspec(dllexport) int SendMessage();
__declspec(dllexport) int Sum(int x, int y);
__declspec(dllexport) int Mul(int x, int y);
__declspec(dllexport) float Div(int x, int y);


int SquareInt(int param) { return param * param;}

int Sum(int x, int y) { return x + y;}

int Mul(int x, int y) { return x * y;}

float Div(int x, int y) { return x / y;}

int SendMessage() { return 100;}