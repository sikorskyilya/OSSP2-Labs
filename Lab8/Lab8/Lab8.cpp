#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
HANDLE hThread1;
DWORD IDThread1;
HANDLE hThread2;
DWORD IDThread2;
HANDLE hThread3;
DWORD IDThread3;
DWORD dwRet;
CRITICAL_SECTION cs;

void CALLBACK a_proc10(DWORD p)
{
	int n = 10;
	DWORD *ptr = (DWORD*)p;
	std::cout << "Async add 10 is called!" << std::endl;
	*ptr += n;
	std::cout << "Async add 10 ended" << std::endl;
}

void CALLBACK a_proc100(DWORD p)
{
	int n = 100;
	DWORD *ptr = (DWORD*)p;
	std::cout << "Async add 100 called" << std::endl;
	*ptr += n;
	std::cout << "Async add 100 ended" << std::endl;
}

void CALLBACK a_writeFile(DWORD p)
{
	std::string buf;
	std::cout << "Async writeFile is called!" << std::endl;
	std::cout << "Input text: " << std::endl;
	EnterCriticalSection(&cs);
	getline(cin, buf);	
	std::ofstream out;         

	out.open("D:\\Subject\\OSI2\\Lab\\Lab8\\text.txt");
	if (out.is_open())
	{
		out << buf << std::endl;
	}
	LeaveCriticalSection(&cs);
	std::cout << "Async writeFile ended" << std::endl;
}

void CALLBACK a_readFile(DWORD p)
{
	std::cout << "Async readFile is called" << std::endl;
	std::string line;
	EnterCriticalSection(&cs);
	std::ifstream in("D:\\Subject\\OSI2\\Lab\\Lab8\\text.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();     // закрываем файл
	LeaveCriticalSection(&cs);
	std::cout << "Async readFile ended" << std::endl;
}

DWORD WINAPI add1(LPVOID ptr)
{
	DWORD* zz = (DWORD*)ptr;
	std::cout << "Thread says: initial count is" << *zz << std::endl;
	SleepEx(INFINITE, TRUE);  // call async. proc
	std::cout << "Thread says: Final count from async proc is" << *zz << std::endl;
	getchar();
	return 0;

}

DWORD WINAPI add2(LPVOID ptr)
{
	DWORD* zz = (DWORD*)ptr;
	std::cout << "Thread says: initial count is" << *zz << std::endl;
	SleepEx(INFINITE, TRUE);  // call async. proc
	std::cout << "Thread says: Final count from async proc is" << *zz << std::endl;
	getchar();
	return 0;
}

DWORD WINAPI file(LPVOID ptr)
{
	std::cout << "Thread file says: START" << std::endl;
	SleepEx(INFINITE, TRUE);  // call async. proc
	std::cout << "Thread file says: END!" << std::endl;
	getchar();
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{

	DWORD count = 10;

	InitializeCriticalSection(&cs);

	hThread1 = CreateThread(NULL, 0, add1, &count, 0, &IDThread1);
	Sleep(100);
	dwRet = QueueUserAPC(a_proc10, hThread1, (DWORD)&count);
	hThread2 = CreateThread(NULL, 0, add2, &count, 0, &IDThread2);
	Sleep(100);
	dwRet = QueueUserAPC(a_proc100, hThread2, (DWORD)&count);
	hThread3 = CreateThread(NULL, 0, file, NULL, 0, &IDThread3);
	Sleep(100);
	dwRet = QueueUserAPC(a_writeFile, hThread3, NULL);
	dwRet = QueueUserAPC(a_readFile, hThread3, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	CloseHandle(hThread1);
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);
	WaitForSingleObject(hThread3, INFINITE);
	CloseHandle(hThread3);
	getchar();
	return 0;
}
