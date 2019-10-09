#pragma once
#include "Obj.h"
#include <windows.h>
class StaticObject :
	public CObj
{
public:
	StaticObject();
	StaticObject(int x, int y, int z_order, bool ani);
	StaticObject(int x, int y, int z_order, bool ani, string img_ID);
	~StaticObject();

	virtual void Collision(int collision_layer_id, CObj* collide_obj) {};
};

