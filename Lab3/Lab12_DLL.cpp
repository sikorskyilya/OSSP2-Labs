#include "stdafx.h"
#include <iostream>
#include "string.h"
#include <string>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <time.h>


using namespace std;

extern "C++" __declspec(dllexport) void W_File()
{
	HANDLE hFile;
	DWORD dwBytesWritten;
	char buf[50];
	cout << "Input string: " << endl;
	fgets(buf, sizeof(buf), stdin);
	ofstream out;
	LPCWSTR pStr = (LPCWSTR)buf;
	out.open("D:\\Subject\\OSI2\\Lab\\Lab3\\Text.txt");
	if (out.is_open())
		out << buf << std::endl;
	std::wcout << "Text len: " << strlen((char*)pStr) << '\n';
}

extern "C++" __declspec(dllexport) void Process()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
		std::wcout << "Error " << '\n';
}

extern "C++" __declspec(dllexport) void F_File()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR filesearch[] = TEXT("D:\\Subject\\OSI2\\Lab\\Lab3\\Text.txt");
	hFind = FindFirstFile(filesearch, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	else
	{
		std::wcout << "Founded: " << FindFileData.cFileName << '\n';
		while (FindNextFile(hFind, &FindFileData) != 0)
			std::wcout << "File: " << FindFileData.cFileName << '\n';
		FindClose(hFind);
	}
}

extern "C" __declspec(dllexport) char* __stdcall CurrDate()
{
	time_t timer = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &timer);
	std::wcout << "Time: " << str << '\n';
	return str;
}



