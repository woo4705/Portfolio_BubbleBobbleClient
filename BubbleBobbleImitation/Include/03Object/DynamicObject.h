#pragma once
#include "Obj.h"

class DynamicObject :
	public CObj
{
public:
	DynamicObject();
	
	DynamicObject(int x, int y, int z_order, bool ani);
	DynamicObject(int x, int y, int z_order, bool ani, string img_ID);
	~DynamicObject();

	virtual void Update(float frameTime)=0; //속도, 위치등을 갱신
	void setVelocity(Velocity v);
	void setAcceleration(Velocity accl);
	void Move(int dir, Velocity velo);
	void Move(int dir, Velocity velo, Velocity accl);
	void Move(int dir);
	

	virtual void Collision(int collision_layer_id, CObj* collide_obj) {};
protected:
	Velocity velocity;
	Velocity acceleration;

	bool vertical_reverse = false;
	
};
