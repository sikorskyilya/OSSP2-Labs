#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include "string.h"
#include "conio.h"

#define STRLEN(x) (sizeof(x)/sizeof(TCHAR)-1)

using namespace std;

HANDLE output;
HANDLE input;
COORD cursor;
int x = 10;
int y = 3;
const TCHAR szMsg[] = L"Input password:";
char carr[10];
DWORD dwCount = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteConsole(output, &szMsg, STRLEN(szMsg), &dwCount, NULL);
	char ch;
	char enter = ' ';
	int i = 0;
	while ((ch = _getch()) != 13)
	{
		_getch();

		if (ch == 13)
			enter = ch;
		else
		{
			carr[i] = ch;
		}
		ch = '*';
		cout << ch;
		i++;
	}
	cout << "\nPassword: " << std::endl;
	for(i=0;i< strlen(carr);i++)
		cout << carr[i];
	cout << "\n";
	system("pause");
	return 0;
}
