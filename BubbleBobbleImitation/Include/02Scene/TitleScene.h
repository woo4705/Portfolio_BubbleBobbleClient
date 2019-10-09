#pragma once
#include "Scene.h"
#include "../Core.h"
class TitleScene :
	public CScene
{

private:
	static TitleScene* title_Inst;
	CCore* coreInst = CCore::GetInst();
public:
	TitleScene();
	~TitleScene();
	void InitRender();
	virtual void Render();
	void Update(float frameTime) {} // 동적 오브젝트들을 갱신. 그림
	void Input(float frameTime) {}
	void Collision() {}
	HWND StartBtn, QuitBtn;
	HBITMAP bg_img_file; //테스트용으로 빼놨고 이후 내부로 넣을것

	static TitleScene* GetInst() {
		if (!title_Inst) {
			title_Inst = new TitleScene;
		}
		return title_Inst;
	}



};

