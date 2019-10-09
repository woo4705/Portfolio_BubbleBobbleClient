#pragma once
#include "Macro.h"
#include "resource.h"
#include "GameCommon.h"
class CCore
{

private:
	static CCore* core_Inst;
	static bool		c_bLoop;
	int currentScene; // 현재씬이 무엇인지 알고, 그에 따른 명령 처리를 위하여
	float time_stack;
	ATOM MyRegisterClass();
	BOOL Create();
	
public:
	bool Init(HINSTANCE hInst);
	int Run();
	void ExecuteGameLoop();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	HDC		c_hDC; 
	HWND	c_hWnd; 
	HINSTANCE		c_hInst;
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 120, 0));
	HWND my_Btn;
protected:
	
	HRESULT c_hr; //32bit형 정수로, 함수의 성공/실패여부를 나타낸다. Success=0, Fail=1

	LARGE_INTEGER timeStart;
	LARGE_INTEGER timeEnd;
	LARGE_INTEGER timeFreq;

	float frameTime;
	float fps;
	DWORD sleepTime;
	bool paused;
	bool initialized;


public:
	CCore();
	~CCore();

	static CCore* GetInst() {
		if (!core_Inst) {
			core_Inst = new CCore; 
		}
		return core_Inst;
	}

	static void DestroyInst() {
		SAFE_DELETE(core_Inst);
	}

	void UpdateCurrentScene(int scene_no) { currentScene = scene_no; }


};

