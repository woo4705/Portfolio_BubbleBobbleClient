#pragma once
#include "../03Object/StaticObject.h"
#include "../03Object/DynamicObject.h"
#include <list>
class CLayer
{
public:
	CLayer();
	CLayer(int id, int z);
	~CLayer();

private:
	int z_order;
	int id;
	HDC StaticObjectDC;
	CCore* core_Inst = CCore::GetInst();

	void Initialize();

public:
	void SetZOrder(int z) { this->z_order = z; }
	int GetZOrder() { return this->z_order; } //static으로 해야하나.. 가상함수로 해야하나
	int GetID() { return this->id; } //많이쓰이는만큼 좀더 효율을 높이는 패턴은 없는지 알아보자

	void addStaticObj(StaticObject* obj) { static_obj_list.push_back(obj); }
	void clearStaticObjList();

	void addDynamicObj(DynamicObject* obj) { dynamic_obj_list.push_back(obj); }

	void InitRender(HDC back_DC);
	void Update(float frameTime);
	void Collision();
	void Render(HDC back_DC);

	void CheckIsCollide(int collision_layer_id ,CObj* obj);
	bool CheckCollideX(CObj* itr_obj, CObj* layer_obj);
	bool CheckCollideY(CObj* itr_obj, CObj* layer_obj);
	list<class StaticObject*> static_obj_list; //왜 클래스 안붙이면 안될까
	list<class DynamicObject*> dynamic_obj_list;
	vector<CLayer*> collision_interact_layer_list;

	//void addDynamicObj(StaticObject* obj) { dynamic_obj_list.push_back(obj); }
};

