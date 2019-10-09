#include "stdafx.h"
#include "Core.h"
#include "02Scene\TitleScene.h"
#include "02Scene\GameStageScene.h"
#include "04Network\TCPNetwork.h"

CCore::CCore()
{
	
}


CCore::~CCore()
{
}

DWORD WINAPI RunGameLogic(void* lpVoid)
{
	CCore::GetInst()->ExecuteGameLoop();
	return 0;
}

DWORD WINAPI SendPacket(void* lpVoid)
{
	TCPNetwork::GetInst()->ReceivePacket();
	return 0;
}

DWORD WINAPI RecvPacket(void* lpVoid)
{
	TCPNetwork::GetInst()->ReceivePacket();
	return 0;
}


CCore* CCore::core_Inst = NULL; 


bool CCore::c_bLoop = true;
LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	
	case WM_COMMAND: {
		switch (core_Inst->currentScene) {
			case Scene_enum::Title_Scene: {
				HDC btnDC = (HDC)wParam;
				HWND btnWnd = (HWND)lParam;

				if (TitleScene::GetInst()->StartBtn == btnWnd) {
					// ���Ӿ����� �Ѿ��.
					SetWindowPos(TitleScene::GetInst()->StartBtn, NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
					SetWindowPos(TitleScene::GetInst()->QuitBtn, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
					DeleteObject(core_Inst->hBrush);
					TitleScene::GetInst()->Render();
					GameStageScene* gs = GameStageScene::GetInst();
					gs->initializeLevel(0);
					gs->InitRender();

					core_Inst->currentScene = Scene_enum::InGame_Scene;
					}
				}
				break;
			}  
		
	}
	break;

	case WM_CTLCOLORBTN: {
		
		switch (core_Inst->currentScene) {
			case Scene_enum::Title_Scene: {
				if (core_Inst->hBrush == NULL) {
					core_Inst->hBrush = CreateSolidBrush(RGB(0, 0, 0));
				}

				HDC btnDC = (HDC)wParam;
				HWND btnWnd = (HWND)lParam;

				if (TitleScene::GetInst()->StartBtn == btnWnd) {
					SetBkMode(btnDC, TRANSPARENT);  // makes the background of the text transparent
					SetTextColor(btnDC, RGB(255, 255, 255));  // sets a white text color
					TextOut(btnDC, 30, 2, L"Start", 5);
				}

				if (TitleScene::GetInst()->QuitBtn == btnWnd) {
					SetBkMode(btnDC, TRANSPARENT);  // makes the background of the text transparent
					SetTextColor(btnDC, RGB(255, 255, 255));  // sets a white text color
					TextOut(btnDC, 30, 2, L"Quit", 4);
				}

				DeleteObject(core_Inst->hBrush);
				break;
			}

			case Scene_enum::InGame_Scene: {
				
			}
		}

		return (LRESULT)CreateSolidBrush(RGB(10, 10, 10));
		break;
	}


	case WM_CTLCOLORSTATIC: {
		HDC textDC = (HDC)wParam;
		HWND textWnd = (HWND)lParam;
		//���� ǥ��.
		if (core_Inst->hBrush == NULL) {
			core_Inst->hBrush = CreateSolidBrush(RGB(0, 0, 0));
		}
		SetBkMode(textDC, TRANSPARENT);
		SetTextColor(textDC, RGB(0, 255, 0));

		int p1_score = GameStageScene::GetInst()->player->GetScore();
		wchar_t buffer[8];

		wsprintfW(buffer, L"%d", p1_score);

		HFONT myFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Gill Sans");
		HFONT oldFont = (HFONT)SelectObject(textDC, myFont);
		TextOut(textDC, 970, 150, buffer, wcslen(buffer)); //���ڼ���ŭ
		DeleteObject(oldFont);
		DeleteObject(myFont);
		return (LRESULT)core_Inst->hBrush;
		break;
	}

	case WM_PAINT:
	{
		//OutputDebugString(L"WM_PAINTȣ��\n");
		PAINTSTRUCT ps;
		HDC c_hdc = BeginPaint(CCore::GetInst()->c_hWnd, &ps);

		/// TODO: Add any drawing code that uses hdc here...
		EndPaint(CCore::GetInst()->c_hWnd, &ps);
	}
	break;

	case WM_CREATE: {
		
	}
		break;

	case WM_DESTROY:
		OutputDebugString(L"WM_DESTROYȣ��\n");
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


bool CCore::Init(HINSTANCE hInst) {	
	c_hInst = hInst;
	MyRegisterClass();
	c_bLoop = true;

	//ȭ�����
	Create();
	//ȭ��DC����
	c_hDC = GetDC(c_hWnd);
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	currentScene = Scene_enum::Title_Scene;
	TitleScene* t = TitleScene::GetInst();
	t->InitRender();
	SendMessage(t->StartBtn, WM_CTLCOLORBTN, (WPARAM)c_hDC, (LPARAM)t->StartBtn);
	QueryPerformanceFrequency(&timeFreq);
	QueryPerformanceCounter(&timeStart);
	return true;
}

int CCore::Run()
{
	MSG msg;
	TCPNetwork::GetInst();

	while (c_bLoop) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) c_bLoop = false;
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		else {
			HANDLE hLogicThread = CreateThread(NULL, 0, RunGameLogic, NULL, 0, NULL);
			HANDLE hPacketSendThread = CreateThread(NULL, 0, SendPacket, NULL, 0, NULL);
			HANDLE hPacketRecvThread = CreateThread(NULL, 0, SendPacket, NULL, 0, NULL);

			WaitForSingleObject(hLogicThread,5);
			CloseHandle(hLogicThread);

			//TODO: Packet���� Type�� ���� ó���� �����ϰ� ��Ʈ��ũ ���� ��������� ���۽�Ű�� ó���Ѵ�.
		}
	}
	return (int)msg.wParam;
}

void CCore::ExecuteGameLoop()
{
	QueryPerformanceCounter(&timeEnd);
	frameTime = (float)(timeEnd.QuadPart - timeStart.QuadPart) / ((float)timeFreq.QuadPart);
	timeStart = timeEnd;

	time_stack = 0;
	switch (currentScene)
	{
	case Scene_enum::InGame_Scene: {
		GameStageScene::GetInst()->Input(frameTime);
		GameStageScene::GetInst()->Update(frameTime);
		GameStageScene::GetInst()->Collision();
		GameStageScene::GetInst()->Render();

		break;
	}
	default:
		break;
	}
}



ATOM CCore::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = CCore::WndProc; //����
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = c_hInst;
	wcex.hIcon = LoadIcon(c_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"Puyopuyo";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL CCore::Create()
{
	c_hWnd = CreateWindowW(L"Puyopuyo", L"������", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, c_hInst, nullptr); 
	if (!c_hWnd)
	{
		return FALSE;
	}

	RECT rc = { 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT};
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	/* ������ ������ ũ��� ������ Ŭ���̾�Ʈ ������ ũ�⸦
	���ϴ� ũ��� ������Ѵ�. */

	//�ֻ�ܿ� ���� ��.
	// ZORDER�� ���� â���� ����������, ��� ���� ����� ������
	SetWindowPos(c_hWnd, HWND_TOPMOST, 100, 100,rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER);
	ShowWindow(c_hWnd, SW_SHOW); //nCmdShow �μ����� �����ְ� ��������(�ִ�ȭ/â��� ��)�� �°� ������.	
	UpdateWindow(c_hWnd);

	return TRUE;
}
