// ActiveXCPP2.cpp: реализация CActiveXCPP2App и регистрация DLL.

#include "stdafx.h"
#include "ActiveXCPP2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CActiveXCPP2App theApp;

const GUID CDECL _tlid = { 0x780A93DF, 0xE56F, 0x40E3,{ 0x84, 0x3F, 0x29, 0x87, 0x10, 0xFC, 0x66, 0x19 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CActiveXCPP2App::InitInstance - инициализация DLL

BOOL CActiveXCPP2App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Добавьте здесь свой код инициализации модуля.
	}

	return bInit;
}



// CActiveXCPP2App::ExitInstance - завершение DLL

int CActiveXCPP2App::ExitInstance()
{
	// TODO: Добавьте здесь свой код завершения работы модуля.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - добавляет записи в системный реестр

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - удаляет записи из системного реестра

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
