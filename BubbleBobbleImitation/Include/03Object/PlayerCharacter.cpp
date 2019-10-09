
#include "PlayerCharacter.h"

#include "../02Scene/GameStageScene.h"
#include "BubbleProjectile.h"
#include "EnemyCharacter.h"
#include "Item.h"
#include <string>
PlayerCharacter::PlayerCharacter()
{
}

PlayerCharacter::PlayerCharacter( string img_ID, int z_ord, bool ani)
{
	//this->refScene = scene;
	this->img_id = img_ID;
	this->z_order = z_ord;
	this->animated = ani;
	this->frame_num = 6;

	isAlive = true;
	this->time_per_frame = 0.06f;
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Input(float frameTime)
{
	if (GetAsyncKeyState('W') & 0x0001) {
		if (isFalling || jump_remain_distance >= 0.01f) return;
		else jump_remain_distance = 150.f;
		isFalling = true;
	}

	if (GetAsyncKeyState('A') & 0x8000) {
		horizontal_reversed = false;

		acc_frame_time += frameTime;
		if (acc_frame_time >= time_per_frame) UpdateFrame();
		
		for (int i = 0; i <= height / TILE_SIZE; i++) {
			if (GameStageScene::GetInst()->GetTileInfo((int)x_pos -1, (int)(y_pos + i*TILE_SIZE)) != 0 ) return;
		}
		Move(Move_Direction::Left, Velocity(200.f*frameTime, 0));

	}

	if (GetAsyncKeyState('D') & 0x8000) {
		horizontal_reversed = true;

		acc_frame_time += frameTime;
		if (acc_frame_time >= time_per_frame) UpdateFrame();

		for (int i = 0; i <= height / TILE_SIZE; i++) {
			if (GameStageScene::GetInst()->GetTileInfo((int)x_pos + width +1, y_pos + i*TILE_SIZE) != 0)
				return;
		}
		Move(Move_Direction::Right, Velocity(200.f*frameTime, 0));
	}


	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (remain_shot_delay > 0.01f) {
			return;
		}
		else {
			remain_shot_delay = 0.3f;
			BubbleProjectile* bubble;

			if (!horizontal_reversed) {
				bubble = new BubbleProjectile(BubbleType::Bubble_1P, x_pos, y_pos);
				bubble->SetBubbleProperty(Move_Direction::Left, 192.f, 3.0f);
			}
			else {
				bubble = new BubbleProjectile(BubbleType::Bubble_1P, x_pos + width , y_pos);
				bubble->SetBubbleProperty(Move_Direction::Right, 192.f, 3.0f);
			}
			bubble->SetShootVelocity(400.f);
			GameStageScene::GetInst()->GetLayerById(GameScene_LayerID::Player_projectile)->addDynamicObj(bubble);
		}		
	}
}



void PlayerCharacter::Update(float frameTime) {
	remain_shot_delay -= frameTime;

	if (jump_remain_distance >= 0.01f) {
		Move(Move_Direction::Up, Velocity(0, 400.f*frameTime));
		jump_remain_distance -= 400.f*frameTime;
		return;
	}
	else {

		for (int i = 0; i <= width / TILE_SIZE; i++) {
			if (GameStageScene::GetInst()->GetTileInfo((int)x_pos + i*TILE_SIZE, y_pos + height) != 0
				&& this->y_pos > this->height + TILE_SIZE) {
				//조건문에서 아래의 것은 윗쪽 화면밖으로 나가면 떨어지도록 한 것인데, 만일 워프되는 곳이 있다면 그 부분을 고려해봐야함
				isFalling = false;
				return;
			}
		}
		isFalling = true;
		Move(Move_Direction::Down, Velocity(0, 200.f*frameTime)); //air flow영향?
		// 한번 땅 닿기전엔 점프못하게 하기
	}
}

void PlayerCharacter::Collision(int collision_layer_id, CObj * collide_obj) {
	switch (collision_layer_id)
	{
		case GameScene_LayerID::Player_projectile: {
			BubbleProjectile* collide_bubble = (BubbleProjectile*)collide_obj;
			switch (collide_bubble->GetBubbleType()) {
				case BubbleType::Bubble_1P: {
					if (collide_bubble->GetForceRange() < 0.01f) collide_obj->SetAlive(false);
					break;
				}

				case BubbleType::Bubble_2P: {
					if (collide_bubble->GetForceRange() < 0.01f) collide_obj->SetAlive(false);
					break;
				}

				case BubbleType::Monster_Captured: {
					collide_bubble->ThrowCatchedMonster();
				}
			}
			break;
		}


		case GameScene_LayerID::Enemy: {
			EnemyCharacter* collide_enemy = (EnemyCharacter*)collide_obj;
			if (!collide_enemy->GetIsThrown()) {
				//TODO: Life시스템이 구현되면 -1
			}
			
			break;
		}


		case GameScene_LayerID::Item: {
			ItemObject* item = (ItemObject*)collide_obj;
			item->PickItem(this);
			break;
		}
	}

}
