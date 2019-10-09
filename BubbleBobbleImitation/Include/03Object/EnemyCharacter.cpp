#include "EnemyCharacter.h"
#include "../02Scene/GameStageScene.h"
#include "BubbleProjectile.h"

EnemyCharacter::EnemyCharacter()
{
	this->animated = true;
	isAlive = true;
	commandList = vector<int>();
}

EnemyCharacter::EnemyCharacter(int monster_type, int z_order)
{
	this->monster_type = monster_type;
	this->z_order = z_order;
	this->animated = true;
	isAlive = true;
	commandList = vector<int>();
	switch (monster_type) {
		case MonsterType::Zen_Chan: {
			img_id = "zen_chan_walk";
			break;
		}
	}
}


EnemyCharacter::~EnemyCharacter() {
}


void EnemyCharacter::SetAnimationInfo(int frame_num, float time_per_frame)
{
	this->frame_num = frame_num;
	this->time_per_frame = time_per_frame;
}



void EnemyCharacter::Update(float frameTime) {
	
	if (move_range <= 0) {
		if (cmd_idx >= commandList.size()) {
			cmd_idx = 0;
			return;
		}
		ExecuteCommand(commandList[cmd_idx], 1);
		cmd_idx++;
		
	}
	isFalling = true;


	if (jump_remain_distance >= 0.01f) {
		Move(Move_Direction::Up, Velocity(0, 200.f*frameTime));
		jump_remain_distance -= 200.f*frameTime;
		return;
	}
	else {
		for (int i = 0; i <= width / TILE_SIZE; i++) {
			if (GameStageScene::GetInst()->GetTileInfo((int)x_pos + i*TILE_SIZE +1, y_pos + height) != 0) {
				isFalling = false;
				break;
			}
		}
		if (isFalling) {
			Move(Move_Direction::Down, Velocity(0, 200.f*frameTime));
		}
		// 한번 땅 닿기전엔 점프못하게 하기
	}


	switch (state) {
		case EnemyAICommand::Move_Left: {
			horizontal_reversed = false;
			// 왼쪽에 타일로 막히면 명령 종료
			if (isFalling) return;
			acc_frame_time += frameTime;
			if (acc_frame_time >= time_per_frame) UpdateFrame();

			for (int i = 0; i <= height / TILE_SIZE; i++) {
				if (GameStageScene::GetInst()->GetTileInfo((int)x_pos, (int)(y_pos + i*TILE_SIZE)) != 0) {
					move_range = 0;
					return;
				}
			}
			//아니면 움직이기
			Move(Move_Direction::Left, Velocity(velocity.x_velo*frameTime,0));
			move_range -= velocity.x_velo* frameTime;
			break;
		}

		case EnemyAICommand::Move_Right: {
			horizontal_reversed = true;
			if (isFalling) return;
			acc_frame_time += frameTime;
			if (acc_frame_time >= time_per_frame) UpdateFrame();
			for (int i = 0; i <= height / TILE_SIZE; i++) {
				if (GameStageScene::GetInst()->GetTileInfo((int)x_pos + width, y_pos + i*TILE_SIZE) != 0) {
					move_range = 0;
					return;
				}	
			}
			Move(Move_Direction::Right, Velocity(velocity.x_velo*frameTime, 0));
			move_range -= velocity.x_velo* frameTime;
			break;
		}

		case EnemyAICommand::Jump: {
			if (jump_remain_distance <= 0.01f && !isFalling) move_range=0;
		}
	}
	
}


void EnemyCharacter::ExecuteCommand(int Command, int unit) {
	switch (Command)
	{
		case EnemyAICommand::Move_Left: {
			move_range = unit*TILE_SIZE;
			state = EnemyAICommand::Move_Left;
			break;
		}

		case EnemyAICommand::Move_Right: {
			move_range = unit*TILE_SIZE;
			state = EnemyAICommand::Move_Right;
			break;
		}

		case EnemyAICommand::Jump: {
			move_range = unit*TILE_SIZE;
			move_range = 136.f;
			jump_remain_distance = 136.f;
			state = EnemyAICommand::Jump;
			break;
		}
	}
}


void EnemyCharacter::Collision(int collision_layer_id, CObj * collide_obj)
{
	switch (collision_layer_id)
	{
	case GameScene_LayerID::Player_projectile:
		BubbleProjectile* collide_bubble = (BubbleProjectile*)collide_obj;
		if (collide_bubble->GetForceRange() > 0.01f) {

			collide_bubble->CatchMonster(this->monster_type);
			this->SetAlive(false);
		}
		break;

	}
}

