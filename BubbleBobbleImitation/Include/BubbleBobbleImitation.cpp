// BubbleBobbleImitation.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "BubbleBobbleImitation.h"
#include "Core.h"
#define MAX_LOADSTRING 100

// Global Variables:
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	// TODO: Place code here.
	if (!CCore::GetInst()->Init(hInstance)) { //객체생성이 실패하면 메모리 해체
		CCore::DestroyInst();
		return 0;
	}

	int iRev = CCore::GetInst()->Run();

	CCore::DestroyInst();

	return  iRev;
	
}


