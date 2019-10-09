#pragma once
#include "DynamicObject.h"
#include "DyingEnemy.h"
class BubbleProjectile :
	public DynamicObject
{
	friend class EnemyCharacter;
public:
	BubbleProjectile();
	BubbleProjectile(int type, int x_pos, int y_pos);
	~BubbleProjectile();

	void SetShootVelocity(float x) {
		this->shoot_velocity.x_velo = x;
		this->shoot_velocity.y_velo = 0;
	}

	void SetBubbleProperty(int dir, float fr, float lt);

	void Update(float frameTime);
	virtual void Collision(int collision_layer_id, CObj* collide_obj) {}
	
	void CatchMonster(int moster_type);
	void ThrowCatchedMonster();

private:
	float force_range = 1.f;
	float life_time = 1.f;
	Velocity shoot_velocity;
	int direction = 0;
	int bubble_type;

	int catched_monster_type = -1; // 포획된 몬스터 정보를 불러올지 아닐지 

public:
	int GetBubbleType() { return this->bubble_type; }
	void SetBubbleType(int type) { this->bubble_type = type; }

	int GetForceRange() { return this->force_range; }
	void SetForceRange(float fr) { this->force_range = fr; }

	
};

