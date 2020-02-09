#include "stdafx.h"
#include <windows.h>
//#include "MyDllLab.h"
#include <iostream>



typedef int(*f_funci)();
typedef int( *f_funci1)(int x, int y);
typedef int( *f_funci2)(int x, int y);
typedef float(*f_funci3)(int x, int y);

int main()
{


	HINSTANCE hProcID = LoadLibrary(TEXT("D:\\Subject\\OSI2\\Lab\\Lab4\\Debug\\MFCLibrary1.dll"));


	if (!hProcID) {
		std::cout << "could not load the dynamic library\n" << GetLastError() << std::endl;
		return EXIT_FAILURE;
	}

	f_funci funci = (f_funci)GetProcAddress(hProcID, "SendMessage");
	f_funci1 sum = (f_funci1)GetProcAddress(hProcID, "Sum");
	f_funci2 mul = (f_funci2)GetProcAddress(hProcID, "Mul");
	f_funci3 div = (f_funci3)GetProcAddress(hProcID, "Div");

	if (!funci && !sum && !mul && !div) {
		std::cout << "could not locate the function\n" << GetLastError() << std::endl;
		getchar();
		FreeLibrary(hProcID);
		return EXIT_FAILURE;
	}
	std::cout << "Sum 1+2: " << (sum)(1,2) << std::endl;
	std::cout << "Mul 2*3: " << (mul)(2,3) << std::endl;
	std::cout << "Div 10/2: " << (div)(10,2) << std::endl;

	system("pause");
	FreeLibrary(hProcID);
	return EXIT_SUCCESS;
}

