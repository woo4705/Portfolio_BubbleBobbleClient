#pragma once
#include "DynamicObject.h"
class EnemyCharacter :
	public DynamicObject
{
	
public:
	EnemyCharacter();
	EnemyCharacter(int monster_type, int z_order);
	~EnemyCharacter();
	virtual void SetAnimationInfo(int frame_x_cnt, float time_per_frame);

	virtual void Update(float frameTime);
	void ExecuteCommand(int Command, int unit);
	virtual void Collision(int collision_layer_id, CObj* collide_obj);
	
	vector<int> commandList;

	bool GetIsThrown() { return this->isThrown; }
private:
	int monster_type;

	float jump_remain_distance = 0;
	float remain_shot_delay = 0;
	bool isFalling = false;

	int state = (int)EnemyAICommand::Idle;
	bool isCmdLoop = true;
	int cmd_idx = 0, loop_from=0;

protected:
	float move_range = 0;
	bool isThrown = false;
};

