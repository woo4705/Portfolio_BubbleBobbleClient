#pragma once
#include "DynamicObject.h"
class PlayerCharacter :
	public DynamicObject
{
public:
	PlayerCharacter();
	PlayerCharacter(string img_ID, int z_order, bool ani);
	~PlayerCharacter();
	void Input(float frameTime);
	void Update(float frameTime);
	virtual void Collision(int collision_layer_id, CObj* collide_obj);
	


private:
	bool player_flag; //1P�� 1, 2P�� 0. �� �÷��̾�� �ϳ��� ����. �ߺ��ϸ� ���ϰ�
	int player_score = 0;

public:
	int GetScore() { return player_score; }
	void PlusScore(int plus) { player_score += plus; }
	void ResetScore() { player_score = 0; }

private:
	float jump_remain_distance = 0;
	float remain_shot_delay = 0;
	bool isFalling = false;

	//vector<CLayer*> interactObject;
	//Input�� ���� �����̱�
};

