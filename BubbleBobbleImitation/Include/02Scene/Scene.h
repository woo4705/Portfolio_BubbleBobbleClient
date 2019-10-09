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
	virtual void Update(float frameTime) = 0; // ���� ������Ʈ���� ����
	virtual void Collision() = 0;
	virtual void Render();
	void CallScene(); //ȣ���� ������ݱ�
	
protected:
	int s_id;
	HDC back_bufferDC;
	vector<CLayer*> refLayer;

public:
	virtual void addLayer(CLayer* layer);
	//virtual void deleteLayer(CLayer* layer);

};

