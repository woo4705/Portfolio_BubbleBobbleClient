#include "Obj.h"
#pragma comment(lib, "msimg32.lib")

CObj::CObj()
{
}


CObj::~CObj()
{
}

void CObj::SetSize(int w, int h) {
	this->width = w;
	this->height = h;
}

void CObj::SetRadius(int r) {
	this->radius = r;
}

void CObj::Render(HDC back_hDC) {
	//OutputDebugString(L"Rendering\n");

	HDC hCompatibleDC = CreateCompatibleDC(back_hDC);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hCompatibleDC, resource_Inst->GetResourceById(img_id));


	if (animated == false) {
		if (TransparentBlt(back_hDC, x_pos, y_pos, width, height, hCompatibleDC, 0, 0, width, height, RGB(102,102,102))) {
			SelectObject(hCompatibleDC, hOldBitmap);		
		}
	}
	else {
		//동적으로 bitmap 크기에 맞게 바꾸기
		if (horizontal_reversed == false) {
			if (TransparentBlt(back_hDC, x_pos, y_pos, width, height, hCompatibleDC, width*frame_counter, 0, width, height, RGB(102, 102, 102))) {
				SelectObject(hCompatibleDC, hOldBitmap);
			}
			else {
				resource_Inst->ClearLoadedResource(img_id);
			}
		}
		else {
			HDC MemDC = CreateCompatibleDC(back_hDC);
			HBITMAP preBitMap = CreateCompatibleBitmap(back_hDC, width, height);
			HBITMAP oldBitMap = (HBITMAP)SelectObject(MemDC, preBitMap);

			if (StretchBlt(MemDC, 0, 0, width, height, hCompatibleDC, width*(frame_counter + 1) -1, 0, (-1 * width), height, SRCCOPY)) {
				SelectObject(hCompatibleDC, hOldBitmap);
				TransparentBlt(back_hDC, x_pos, y_pos, width, height, MemDC, 0, 0, width, height, RGB(102, 102, 102));
				SelectObject(MemDC, oldBitMap);
				DeleteObject(preBitMap);
				ReleaseDC(core_Inst->c_hWnd, MemDC);
				DeleteDC(MemDC);
				DeleteObject(oldBitMap);
			}
			else {
				resource_Inst->ClearLoadedResource(img_id);
			}
		}
	}
	
	ReleaseDC(core_Inst->c_hWnd, hCompatibleDC);
	DeleteDC(hCompatibleDC);
	DeleteObject(hOldBitmap);
}


void CObj::UpdateFrame() {
	this->acc_frame_time = 0;
	this->frame_counter++;

	if (frame_counter >= frame_num) {
		frame_counter = 0;
	}
}
