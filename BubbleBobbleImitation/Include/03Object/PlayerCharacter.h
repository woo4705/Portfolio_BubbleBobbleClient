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
	
	void SetHorizontalReversed(bool val) {
		horizontal_reversed = val;
	}

	void AddAccFrameTime(float frameTime);
	void DoJump();
	bool CheckVaildMove(int nextXpos, int nextYpos);
	bool IsJumpable();

	void SetPlayerID(INT16 id) {
		this->m_characterID = id;
	}

	INT16 GetPlayerID() {
		return m_characterID;
	}

private:
	int player_score = 0;
	INT16 m_characterID = 0; //플레이어를 구분하는 고유의 값

public:
	int GetScore() { return player_score; }
	void PlusScore(int plus) { player_score += plus; }
	void ResetScore() { player_score = 0; }

private:
	float jump_remain_distance = 0;
	float remain_shot_delay = 0;
	bool isFalling = false;

	//vector<CLayer*> interactObject;
	//Input에 따라 움직이기
};

