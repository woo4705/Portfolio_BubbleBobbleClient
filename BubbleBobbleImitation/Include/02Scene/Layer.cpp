#include "Layer.h"

using namespace std;
CLayer::CLayer()
{
}

CLayer::CLayer(int ID,int z) {
	this->id = ID;
	this->z_order = z;
	collision_interact_layer_list = vector<CLayer*>();
}


CLayer::~CLayer()
{
	ReleaseDC(core_Inst->c_hWnd, StaticObjectDC);
}

void CLayer::Initialize(){
	
}


void CLayer::InitRender(HDC back_DC)
{
	StaticObjectDC = CreateCompatibleDC(back_DC); 
	HBITMAP preBitMap = CreateCompatibleBitmap(back_DC, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	HBITMAP oldBitMap = (HBITMAP)SelectObject(StaticObjectDC, preBitMap);

	list<StaticObject*>::iterator itr;
	list<StaticObject*>::iterator itr_end;

	itr = static_obj_list.begin();
	itr_end = static_obj_list.end();

	for (; itr != itr_end; itr++) {
		(*itr)->Render(StaticObjectDC);
	}

	BitBlt(back_DC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, StaticObjectDC, 0, 0, SRCCOPY);

}

void CLayer::Update(float frameTime) {
	list<DynamicObject*>::iterator d_itr;
	list<DynamicObject*>::iterator d_itr_end;
	d_itr = dynamic_obj_list.begin();
	d_itr_end = dynamic_obj_list.end();

	for (; d_itr != d_itr_end; d_itr++) {
		(*d_itr)->Update(frameTime);
	}
}

void CLayer::Collision() {
	vector<CLayer*>::iterator c_layer_itr = collision_interact_layer_list.begin();
	vector<CLayer*>::iterator c_layer_itr_end = collision_interact_layer_list.end();

	for (; c_layer_itr != c_layer_itr_end; c_layer_itr++) {
		list<StaticObject*>::iterator cl_Sobj_itr = (*c_layer_itr)->static_obj_list.begin();
		list<StaticObject*>::iterator cl_Sobj_itr_end = (*c_layer_itr)->static_obj_list.end();
		for (; cl_Sobj_itr != cl_Sobj_itr_end; cl_Sobj_itr++) {
			CheckIsCollide((*c_layer_itr)->GetID()  ,*cl_Sobj_itr);
		}

		list<DynamicObject*>::iterator cl_Dobj_itr = (*c_layer_itr)->dynamic_obj_list.begin();
		list<DynamicObject*>::iterator cl_Dobj_itr_end = (*c_layer_itr)->dynamic_obj_list.end();
		for (; cl_Dobj_itr != cl_Dobj_itr_end; cl_Dobj_itr++) {
			CheckIsCollide((*c_layer_itr)->GetID(), *cl_Dobj_itr);
		}
	}
	

	
}



void CLayer::CheckIsCollide(int collision_layer_id, CObj* obj)
{
	list<StaticObject*>::iterator s_itr = static_obj_list.begin();
	list<StaticObject*>::iterator s_itr_end = static_obj_list.end();

	for (; s_itr != s_itr_end; s_itr++) {
		if (CheckCollideX(*s_itr, obj) == true && CheckCollideY(*s_itr, obj) == true) {
			(*s_itr)->Collision(collision_layer_id, obj);
			
			//충돌처리하기
		}
	}

	list<DynamicObject*>::iterator d_itr = dynamic_obj_list.begin();
	list<DynamicObject*>::iterator d_itr_end = dynamic_obj_list.end();

	for (; d_itr != d_itr_end; d_itr++) {
		if (CheckCollideX(*d_itr, obj) == true && CheckCollideY(*d_itr, obj) == true) {
			(*d_itr)->Collision(collision_layer_id, obj);
			//충돌처리하기
		}
	}
}

bool CLayer::CheckCollideX(CObj * itr_obj, CObj * layer_obj)
{
	int itr_l, itr_t, itr_r, itr_b;
	int obj_l, obj_t, obj_r, obj_b;

	itr_obj->GetPosition(itr_l, itr_t);
	itr_obj->GetSize(itr_r, itr_b);
	itr_r += itr_l; 

	layer_obj->GetPosition(obj_l, obj_t);
	layer_obj->GetSize(obj_r, obj_b);
	obj_r += obj_l;

	if (itr_l < obj_l) {
		if (itr_r >= obj_l && itr_l <= obj_r)  return true;// x좌표를 생각해서 충돌체크		
		else return false;
	}
	else {
		if (obj_r >= itr_l && obj_l <= itr_r) return true;
		else return false;
	}
	
	return false;
}

bool CLayer::CheckCollideY(CObj * itr_obj, CObj * layer_obj)
{
	int itr_l, itr_t, itr_r, itr_b;
	int obj_l, obj_t, obj_r, obj_b;

	itr_obj->GetPosition(itr_l, itr_t);
	itr_obj->GetSize(itr_r, itr_b);
	itr_b += itr_t;

	layer_obj->GetPosition(obj_l, obj_t);
	layer_obj->GetSize(obj_r, obj_b);
	obj_b += obj_t;

	if (itr_t < obj_t) {
		if (itr_b >= obj_t && itr_t <= obj_b)  return true;// x좌표를 생각해서 충돌체크		
		else return false;
	}
	else {
		if (itr_t <= obj_b && obj_t <= itr_b) return true;
		else return false;
	}

	return false;
}



void CLayer::Render(HDC back_DC){
	if(static_obj_list.begin() != static_obj_list.end())
		BitBlt(back_DC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, StaticObjectDC, 0, 0, SRCCOPY);

	list<DynamicObject*>::iterator d_itr;
	list<DynamicObject*>::iterator d_itr_end;
	d_itr = dynamic_obj_list.begin();
	d_itr_end = dynamic_obj_list.end();

	DynamicObject* obj_to_delete;
	/*
	여기서 빼진 오브젝트는 메모리에서 해체하자
	*/
	for (; d_itr != d_itr_end; ) {
		if ((*d_itr)->CheckAlive() == false ) {
			obj_to_delete = *d_itr;
			d_itr = dynamic_obj_list.erase(d_itr);
			d_itr_end = dynamic_obj_list.end();
			delete(obj_to_delete);
		}
		else {
			(*d_itr)->Render(back_DC);
			d_itr++;
		}
	}
}



void CLayer::clearStaticObjList()
{
}
