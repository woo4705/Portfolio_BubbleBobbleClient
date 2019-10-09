#pragma once
#define GAME_WINDOW_WIDTH 1200
#define GAME_WINDOW_HEIGHT 768

enum  Scene_enum
{
	Title_Scene,
	InGame_Scene,
	Game_Over,
};



enum Move_Direction {
	Up,
	Down,
	Left,
	Right
};

struct Velocity {
public:
	float x_velo;
	float y_velo;

	Velocity() {}
	Velocity(float x, float y) {
		this->x_velo = x;
		this->y_velo = y;
	}
};


enum  BubbleType  {
	Bubble_1P,
	Bubble_2P,
	Fire_Bolt,
	Monster_Captured
};

enum MonsterType {
	Zen_Chan=1,
};


enum  EnemyAICommand {
	Idle = 0,
	Move_Right = 1,
	Move_Left =2,
	Jump = 3,
	/*
	Move_Diagnal_LU,
	Move_Diagnal_LD,
	Move_Diagnal_RU,
	Move_Diagnal_RD,
	ShootProjectile,
	*/
};

enum PlayerCharacterType {
	GreenDragon = 0,
	BlueDragon = 1,
};

struct PlayerInfo {
public:
	char* playerID;
	PlayerCharacterType characterType;
};

//float time_scale = 0.1f;