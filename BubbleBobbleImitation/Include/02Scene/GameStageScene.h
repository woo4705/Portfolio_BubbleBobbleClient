#pragma once
#include "Scene.h"
#include "../01Core/FileManager.h"
#include "../01Core/PlayerController.h"
#include "../03Object/EnemyCharacter.h"
#define TILE_SIZE 32

enum GameScene_LayerID {
	Background,
	MapObj,
	Player,
	Enemy,
	Item,
	Player_projectile,
	Enemy_projectile,
	Effect,
	Score_effect,
	Game_status
};



class GameStageScene :
	public CScene
{
public:
	GameStageScene();
	~GameStageScene();

	list<EnemyCharacter*> m_enemiesInStage;
	list<PlayerCharacter*>m_playersInStage;
	WholeStageData* StageData;
	PlayerController* Controller;

	void initializeLevel(int lv);
	void SetTileDictionary();
	void SetTileMap(string map_name);
	void SetEnemyCharacters();
	void SetPlayerCharacter(INT16 playerID);
	void AddMonster();
	


	virtual void InitRender();
	void Collision();
	void Render();
	void StartLevel(); //움직이게 함


	 // 동적 오브젝트들을 갱신. 그림
	void Input(float frameTime);
	void Update(float frameTime);

	static GameStageScene* GetInst() {
		if (!InGameScene_Inst) {
			InGameScene_Inst = new GameStageScene();
		}
		return InGameScene_Inst;
	}

	int GetTileInfo(int x, int y);

private:
	int **tile_arr;
	CLayer *background, *map, *player_layer, *enemy_layer, *item,
		*player_projectile, *enemy_projectile, *effect, *score_effect, *game_status;

	CCore* coreInst = CCore::GetInst();
	FileManager* fileMgrInst = new FileManager();

	static GameStageScene* InGameScene_Inst;
	int score = 0;
	
	unordered_map<int, string> tile_hash_id_name;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //임시로 생성
public:
	CLayer* GetLayerById(int id);
	HWND scoreLabel;
};

