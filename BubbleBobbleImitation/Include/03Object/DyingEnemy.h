#pragma once
#include "EnemyCharacter.h"
class DyingEnemy :
	public EnemyCharacter
{
public:
	DyingEnemy();
	DyingEnemy(int monsterType);
	~DyingEnemy();

	virtual void Update(float frameTime);	
	virtual void Collision(int collision_layer_id, CObj* collide_obj) {}

	void SetThrowInfo(bool isThrowing, short dir, float down_range);
	virtual void SetAnimationInfo(int frame_num, float time_per_frame);

private:
	float move_range = 0;
	short throw_x_dir = 0;
};

