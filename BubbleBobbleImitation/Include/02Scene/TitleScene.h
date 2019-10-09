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
	void Update(float frameTime) {} // ���� ������Ʈ���� ����. �׸�
	void Input(float frameTime) {}
	void Collision() {}
	HWND StartBtn, QuitBtn;
	HBITMAP bg_img_file; //�׽�Ʈ������ ������ ���� ���η� ������

	static TitleScene* GetInst() {
		if (!title_Inst) {
			title_Inst = new TitleScene;
		}
		return title_Inst;
	}



};

