
#include "DyingEnemy.h"
#include "../02Scene/GameStageScene.h"
#include "Item.h"
DyingEnemy::DyingEnemy()
{
	isThrown = true;
}

DyingEnemy::DyingEnemy(int monsterType)
{
	switch (monsterType)
	{
		case MonsterType::Zen_Chan: {
			this->img_id = "zen_chan_thrown";
			isThrown = true;
			animated = true;
		}
	}
}


DyingEnemy::~DyingEnemy()
{
}

void DyingEnemy::Update(float frameTime) {
	acc_frame_time += frameTime;
	if (acc_frame_time >= time_per_frame) {
		UpdateFrame();
	}

	if (y_pos >= 760) y_pos = 0;

	if (isThrown) {
		//���� �������� force�� ������
		if (velocity.y_velo >= 0.01f) { //���δ������°� flag�� �ϰų� �Ÿ��� ���ƾ���
			velocity.y_velo -= 300.f*frameTime;
			Move(Move_Direction::Up, Velocity(velocity.x_velo*frameTime, velocity.y_velo*frameTime));
		}
		else {
			if (move_range <= 0.01f) { isThrown = false; }
			else {
				move_range -= 400.f*frameTime;
				Move(Move_Direction::Down, Velocity(velocity.x_velo*frameTime, 400.f*frameTime));
			}
		}

		if (throw_x_dir == Move_Direction::Left) {
			//���⼭ �� �ε����� ���� �ٲٱ�, �ӵ����� �պ���
			if (x_pos < 32) {
				throw_x_dir == Move_Direction::Right;
				return;
			}

			velocity.x_velo = 100.f*frameTime;
			Move(Move_Direction::Left, Velocity(velocity.x_velo, velocity.y_velo*frameTime));
		}
		else {
			if (x_pos + width > 960 - 32) {
				throw_x_dir == Move_Direction::Left;
				return;
			}

			velocity.x_velo = 100.f*frameTime;
			Move(Move_Direction::Right, Velocity(velocity.x_velo, velocity.y_velo*frameTime));
		}

	}
	else {
		// ������ �����ϱ�
		ItemObject* reward = new ItemObject(1);
		reward->SetPosition(x_pos, y_pos);
		GameStageScene::GetInst()->GetLayerById(GameScene_LayerID::Item)->addDynamicObj(reward);
		isAlive = false;
	}

}

void DyingEnemy::SetThrowInfo(bool isThrowing, short dir, float down_range) {
	this->isThrown = isThrown;
	this->throw_x_dir = dir;
	this->move_range = down_range;
}

void DyingEnemy::SetAnimationInfo(int frame_num, float time_per_frame)
{
	this->frame_num = frame_num;
	this->time_per_frame = time_per_frame;
}

