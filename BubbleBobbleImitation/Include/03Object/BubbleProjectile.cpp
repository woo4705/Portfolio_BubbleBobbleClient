#include "BubbleProjectile.h"
#include "../02Scene/GameStageScene.h"


BubbleProjectile::BubbleProjectile(){
}

BubbleProjectile::BubbleProjectile(int type, int x, int y)
{
	this->bubble_type = type;
	this->x_pos = x;
	this->y_pos = y;

	
	switch (type) {
	case BubbleType::Bubble_1P :
		string img = "fired_bubble";
		this->SetSize(48, 48);
		this->SetRadius(12);
		this->img_id = img;
		animated = true;
		time_per_frame = 0.15f;
		frame_num = 3;
		break;
	}
	
}


BubbleProjectile::~BubbleProjectile()
{
}

void BubbleProjectile::SetBubbleProperty(int dir, float fr, float lt) {
	this->direction = dir;
	this->force_range = fr;
	this->life_time = lt;
	isAlive = true;
}


void BubbleProjectile::Update(float frameTime) {
	acc_frame_time += frameTime;
	if (animated && acc_frame_time > time_per_frame) {
		acc_frame_time = 0;
		if (bubble_type == BubbleType::Bubble_1P) {
			if(frame_counter < frame_num - 1) frame_counter++;
		}
		else {
			frame_counter++;
			if (frame_counter >= frame_num) frame_counter = 0;
		}
	}

	if (force_range > 0.01f) {
		Move(direction, Velocity(shoot_velocity.x_velo* frameTime, 0)); //버블은 항상 좌우방향으로 발사됨
		force_range -= shoot_velocity.x_velo* frameTime;
	}
	else {
		Move(Move_Direction::Up, Velocity(0, 100.f*frameTime));
		//일단 위로 올라가는데 airflow에 따라 변화를 줘야함
	}

	life_time -= frameTime;

	if (life_time <= 0.01f) {
		isAlive = false;
	}

	if (force_range <= 0.01f) {

		switch (this->bubble_type) {
		case BubbleType::Bubble_1P:
			img_id = "floating_bubble";
			animated = false;
			break;
		}
	}
}

void BubbleProjectile::CatchMonster(int monster_type) {
	switch (monster_type) {
		case MonsterType::Zen_Chan: {
			if (this->bubble_type == BubbleType::Bubble_1P) {
				this->bubble_type = BubbleType::Monster_Captured;
				this->img_id = "zen_chan_captured_1P";
				this->SetSize(48, 48);
				this->force_range = 0;
				this->life_time = 20.f; // 테스트용
				this->catched_monster_type = MonsterType::Zen_Chan;
			}
			break;
		}
	}
}

void BubbleProjectile::ThrowCatchedMonster()
{
	int dir = rand() % 2;
	float fall_range = rand() % 200 + 200.f;
	float x_velo = 300.f;

	switch (this->catched_monster_type) {
		case MonsterType::Zen_Chan: {
			DyingEnemy* throwingMonster = new DyingEnemy(this->catched_monster_type);
			throwingMonster->SetPosition(x_pos, y_pos);
			throwingMonster->SetAlive(true);
			throwingMonster->SetSize(48, 48);
			throwingMonster->setVelocity(Velocity(300.f, 400.f));
			short th_dir;
			if (dir == 1) {
				th_dir = Move_Direction::Left;
			}
			else {
				th_dir = Move_Direction::Right;
			}

			throwingMonster->SetThrowInfo(true, th_dir, fall_range);
			throwingMonster->SetAnimationInfo(4, 0.1f);
			GameStageScene::GetInst()->GetLayerById(GameScene_LayerID::Enemy)->addDynamicObj(throwingMonster);
			this->isAlive = false;
			break;
		}
	}
}
