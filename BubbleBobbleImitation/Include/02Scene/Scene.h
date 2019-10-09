#pragma once
#include "Layer.h"
#include <vector>
using namespace std;

class CScene
{
public:
	CScene();
	~CScene();

	int Init();
	int Clear();
	
	virtual void Input(float frameTime)=0;
	virtual void Update(float frameTime) = 0; // 동적 오브젝트들을 갱신
	virtual void Collision() = 0;
	virtual void Render();
	void CallScene(); //호출후 현재씬닫기
	
protected:
	int s_id;
	HDC back_bufferDC;
	vector<CLayer*> refLayer;

public:
	virtual void addLayer(CLayer* layer);
	//virtual void deleteLayer(CLayer* layer);

};

