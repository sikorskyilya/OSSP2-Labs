#include "stdafx.h"
#include "dll.h"
#include<iostream>
#include<conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR file[50];
	cout << "Input word name: " << endl;
	_getws_s(file);
	Doc(file);
	_getch();
	return 0;
}
