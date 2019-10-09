#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
}

DynamicObject::DynamicObject(int x, int y, int z_ord, bool ani)
{
	this->x_pos = x;
	this->y_pos = y;
	this->z_order = z_ord;
	this->animated = ani;
}


DynamicObject::DynamicObject(int x, int y, int z_ord, bool ani, string img_ID)
{
	this->x_pos = x;
	this->y_pos = y;
	this->z_order = z_ord;
	this->animated = ani;
	this->img_id = img_ID;
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::Update(float frameTime)
{
}

void DynamicObject::setVelocity(Velocity v)
{
	velocity.x_velo = v.x_velo;
	velocity.y_velo = v.y_velo;
}

void DynamicObject::setAcceleration(Velocity accl)
{
	this->acceleration = accl;
}

void DynamicObject::Move(int dir, Velocity velo)
{
	switch (dir)
	{
	case Move_Direction::Left:
		x_pos -= velo.x_velo;
		break;
	case Move_Direction::Right:
		x_pos += velo.x_velo;
		break;
	case Move_Direction::Up:
		y_pos -= velo.y_velo;
		break;
	case Move_Direction::Down:
		y_pos += velo.y_velo;
		break;
	default:
		break;
	}
}

void DynamicObject::Move(int dir, Velocity velo, Velocity accl)
{
}

void DynamicObject::Move(int dir)
{
}
