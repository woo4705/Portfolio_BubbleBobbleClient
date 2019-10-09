#include "../stdafx.h"
#include "TitleScene.h"
#include "Layer.h"
#include "../GameCommon.h"

#include "../03Object/StaticObject.h"

TitleScene* TitleScene::title_Inst = NULL;

TitleScene::TitleScene()
{
	// 타이틀배경 불러오기
	CLayer* background = new CLayer(); //background라는 아이디를 준다?
	
	background->SetZOrder(-10);
	//bg_img_file = (HBITMAP)LoadImage(NULL, L"../include/Bmp/Title_Bg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); 
	string img_id = "Title_bg";
	StaticObject* bg_img = new StaticObject(0, 0, 0, false, img_id);
	bg_img->SetSize(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	background->addStaticObj(bg_img);
	addLayer(background);
	
	// 메뉴바 불러오기

}

void TitleScene::InitRender()
{
	std::vector<CLayer*>::iterator itr = refLayer.begin();
	std::vector<CLayer*>::iterator itr_end = refLayer.end();
	//back_bufferDC = GetDC(coreInst->c_hWnd);

	HBITMAP preBitmap = CreateBitmap(30, 30, 1, 24, NULL);
	back_bufferDC = CreateCompatibleDC(coreInst->c_hDC);

	HBITMAP preBitMap = CreateCompatibleBitmap(coreInst->c_hDC, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	HBITMAP oldBitMap = (HBITMAP)SelectObject(back_bufferDC, preBitMap);

	Rectangle(back_bufferDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);

	for (; itr != itr_end; itr++) {
		(*itr)->InitRender(back_bufferDC);
	}

	if (BitBlt(coreInst->c_hDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, back_bufferDC, 0, 0, SRCCOPY)) {
		SelectObject(back_bufferDC, preBitMap);
	}

	Render();

	ReleaseDC(coreInst->c_hWnd, back_bufferDC);
	DeleteObject(preBitMap);
	DeleteObject(oldBitMap);
	DeleteDC(back_bufferDC);

	coreInst->hBrush = CreateSolidBrush(RGB(185, 188, 122));
	StartBtn =CreateWindow(TEXT("BUTTON"),0, WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON| BS_OWNERDRAW,
		200,680,100,20, coreInst->c_hWnd,NULL, coreInst->c_hInst, 0);

	QuitBtn = CreateWindow(TEXT("BUTTON"), 0, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_OWNERDRAW,
		500, 680, 100, 20, coreInst->c_hWnd, NULL, coreInst->c_hInst, 0);

}


void TitleScene::Render() {
	back_bufferDC = CreateCompatibleDC(coreInst->c_hDC);
	bg_img_file = (HBITMAP)LoadImage(NULL, L"../include/Bmp/Title_Bg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	
	HBITMAP hPreBit = (HBITMAP)SelectObject(back_bufferDC, bg_img_file);

	BitBlt(coreInst->c_hDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, back_bufferDC, 0, 0, SRCCOPY);

	if (bg_img_file == NULL) {
		OutputDebugString(L"이미지없음\n");
	}
	else {
		OutputDebugString(L"이미지찾음\n");
	}
	
}

/*
그나저나 Update함수 호출되면 그때 갱신해야하는데....
배경은 한번불러오고 갱신안함

*/

TitleScene::~TitleScene()
{
}


