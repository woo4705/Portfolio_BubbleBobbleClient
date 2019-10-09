#include "GameStageScene.h"
#include "../03Object/BubbleProjectile.h"
#include "../03Object/Item.h"
GameStageScene* GameStageScene::InGameScene_Inst = NULL;

GameStageScene::GameStageScene()
{
	tile_arr = new int*[25]();

	background = new CLayer(GameScene_LayerID::Background, -5); refLayer.push_back(background);
	map = new CLayer(GameScene_LayerID::MapObj, -3); refLayer.push_back(map);
	player_layer = new CLayer(GameScene_LayerID::Player, 20); refLayer.push_back(player_layer);
	enemy_layer = new CLayer(GameScene_LayerID::Enemy, 18); refLayer.push_back(enemy_layer);
	item = new CLayer(GameScene_LayerID::Item, 10); refLayer.push_back(item);
	player_projectile = new CLayer(GameScene_LayerID::Player_projectile, 15); refLayer.push_back(player_projectile);
	enemy_projectile = new CLayer(GameScene_LayerID::Enemy_projectile, 16); refLayer.push_back(enemy_projectile);
	effect = new CLayer(GameScene_LayerID::Effect, 12); refLayer.push_back(effect);
	score_effect = new CLayer(GameScene_LayerID::Score_effect, 12); refLayer.push_back(score_effect);
	game_status = new CLayer(GameScene_LayerID::Game_status, 100); refLayer.push_back(game_status);

	SetTileDictionary();

}


GameStageScene::~GameStageScene()
{
}

void GameStageScene::initializeLevel(int lv){

	//��� �׸���
	StaticObject* bg = new StaticObject(0,0,0,false,"InGame_bg");
	bg->SetSize(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	background->static_obj_list.push_back(bg);
	StageData = new WholeStageData();
	SetTileMap("../include/DataFile/Stage01.dat");
	SetPlayerCharacter();
	SetEnemyCharacters();
}

void GameStageScene::SetTileDictionary()
{
	tile_hash_id_name.insert(pair<int, string>(10, "tile10"));
	tile_hash_id_name.insert(pair<int, string>(11, "tile11"));
	tile_hash_id_name.insert(pair<int, string>(20, "tile20"));
	tile_hash_id_name.insert(pair<int, string>(21, "tile21"));
	tile_hash_id_name.insert(pair<int, string>(30, "tile30"));
	tile_hash_id_name.insert(pair<int, string>(31, "tile31"));
	tile_hash_id_name.insert(pair<int, string>(40, "tile40"));
	tile_hash_id_name.insert(pair<int, string>(41, "tile41"));
	tile_hash_id_name.insert(pair<int, string>(50, "tile50"));
	tile_hash_id_name.insert(pair<int, string>(51, "tile51"));
}


void GameStageScene::SetTileMap(string map_name)
{
	StaticObject* obj;
	fileMgrInst->LoadMapFile(map_name.c_str(), StageData);
	tile_arr = new int* [25]();


	for (int i = 0; i < 25; i++) {
		tile_arr[i] = new int[31]();
		for (int j = 0; j < 30; j++) {
			tile_arr[i][j] = StageData->map(i).block(j);
		}
	}


	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 30; j++) {
			if (tile_arr[i][j] != 0) {
				//DRAW BLOCK
				string s = tile_hash_id_name[tile_arr[i][j]];
				obj = new StaticObject(TILE_SIZE * j, TILE_SIZE * i, 0, false, s);
				obj->SetSize(TILE_SIZE, TILE_SIZE);
				map->static_obj_list.push_back(obj);
			}
		}
	}
}

void GameStageScene::SetEnemyCharacters()
{

	int mon_cnt = StageData->monsters_size();

	for (int i = 0; i< mon_cnt; i++) {
		const WholeStageData_Monster* monster = &StageData->monsters(i);

		EnemyCharacter* enemy = new EnemyCharacter((int)monster->type(), 1);

		//TODO: ���� ������ �� �߰��Ǹ� �ش� ���Ϳ� ���� �ӵ�/ũ��/�ִϸ��̼ǰ��� �����ϵ��� ����
		enemy->setVelocity(Velocity(200.f, 0.f));
		enemy->SetAnimationInfo(4, 0.1f);
		enemy->SetSize(48, 48);
		int xpos = monster->startxpos();
		int ypos = monster->startypos();
		enemy->SetPosition(monster->startxpos(), monster->startypos());

		int cmd_cnt = monster->commands_size();

		for (int j = 0; j < cmd_cnt; j++) {
			enemy->commandList.push_back(monster->commands(i));
		}
		enemiesInStage.push_back(enemy);
	}

	for (EnemyCharacter* eme : enemiesInStage) {
		enemy_layer->addDynamicObj(eme);

	}
	enemy_layer->collision_interact_layer_list.push_back(player_projectile);

}






void GameStageScene::SetPlayerCharacter()
{
	//�÷��̾� ��ġ
	string player_img_id = "1st_player";
	player = new PlayerCharacter(player_img_id, true, 1); //���� 2��° �÷��̾ �����ϱ�
	player->SetPosition(500, 500);
	player->SetSize(48, 48);

	player_layer->addDynamicObj(player);
	player_layer->collision_interact_layer_list.push_back(enemy_layer);
	player_layer->collision_interact_layer_list.push_back(item);
	player_layer->collision_interact_layer_list.push_back(player_projectile);
	player_layer->collision_interact_layer_list.push_back(enemy_projectile);
}

void GameStageScene::AddMonster()
{
	

	//���� ��ġ
	string monster_img_id = "zen_chan_walk";
	/*

	// ====================================================================================
	EnemyCharacter* monster = new EnemyCharacter((int)MonsterType::Zen_Chan, 1); //���� 2��° �÷��̾ �����ϱ�
	monster->SetPosition(300, 300);
	monster->SetSize(48, 48);
	monster->setVelocity(Velocity(200.f, 0.f));
	monster->SetAnimationInfo(4, 0.1f);
	monster->commandList.push_back(pair<int, int>((int)EnemyAICommand::Move_Right, 50));
	monster->commandList.push_back(pair<int, int>((int)EnemyAICommand::Jump, 1));
	monster->commandList.push_back(pair<int, int>((int)EnemyAICommand::Jump, 1));
	monster->commandList.push_back(pair<int, int>((int)EnemyAICommand::Jump, 1));
	monster->commandList.push_back(pair<int, int>((int)EnemyAICommand::Move_Left, 26));

	enemy_layer->addDynamicObj(monster);
	enemy_layer->collision_interact_layer_list.push_back(player_projectile);

	//===========================================================================================
	EnemyCharacter* monster2 = new EnemyCharacter((int)MonsterType::Zen_Chan, 1); //���� 2��° �÷��̾ �����ϱ�
	monster2->SetPosition(500, 300);
	monster2->SetSize(48, 48);
	monster2->setVelocity(Velocity(200.f, 0.f));
	monster2->SetAnimationInfo(4, 0.1f);
	monster2->commandList.push_back(pair<int, int>((int)EnemyAICommand::Move_Left, 50));
	monster2->commandList.push_back(pair<int, int>((int)EnemyAICommand::Jump, 1));
	monster2->commandList.push_back(pair<int, int>((int)EnemyAICommand::Jump, 1));
	monster2->commandList.push_back(pair<int, int>((int)EnemyAICommand::Jump, 1));
	monster2->commandList.push_back(pair<int, int>((int)EnemyAICommand::Move_Right, 26));

	enemy_layer->addDynamicObj(monster2);
	enemy_layer->collision_interact_layer_list.push_back(player_projectile);
	*/

	
	
}





void GameStageScene::InitRender(){
	std::vector<CLayer*>::iterator itr = refLayer.begin();
	std::vector<CLayer*>::iterator itr_end = refLayer.end();
	HBITMAP preBitmap = CreateBitmap(30, 30, 1, 24, NULL);
	//back_bufferDC = GetDC(coreInst->c_hWnd);
	back_bufferDC = CreateCompatibleDC(coreInst->c_hDC);

	HBITMAP preBitMap = CreateCompatibleBitmap(coreInst->c_hDC, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	HBITMAP oldBitMap = (HBITMAP)SelectObject(back_bufferDC, preBitMap);

	Rectangle(back_bufferDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	/*for (; itr != itr_end; itr++) {
		(*itr)->InitRender(back_bufferDC);
	}*/


	background->InitRender(back_bufferDC);
	map->InitRender(back_bufferDC);

	scoreLabel = CreateWindow(TEXT("STATIC"), L"OnlyText", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		980, 150, 100, 20, coreInst->c_hWnd, NULL, coreInst->c_hInst, 0);
	HWND core_hwnd = CCore::GetInst()->c_hWnd;
	HDC core_hdc = GetDC(core_hwnd);

	SendMessage(coreInst->c_hWnd, WM_CTLCOLORSTATIC, (WPARAM)back_bufferDC, (LPARAM)scoreLabel);

	BitBlt(coreInst->c_hDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, back_bufferDC, 0, 0, SRCCOPY);

	SelectObject(back_bufferDC, preBitmap);
	ReleaseDC(coreInst->c_hWnd, back_bufferDC);
}


void GameStageScene::Collision(){

	std::vector<CLayer*>::iterator itr = refLayer.begin();
	std::vector<CLayer*>::iterator itr_end = refLayer.end();

 	for (; itr != itr_end; itr++) {
		(*itr)->Collision();
	}
}


void GameStageScene::Render()
{
	std::vector<CLayer*>::iterator itr = refLayer.begin();
	std::vector<CLayer*>::iterator itr_end = refLayer.end();
	back_bufferDC = CreateCompatibleDC(coreInst->c_hDC);

	HBITMAP preBitMap = CreateCompatibleBitmap(coreInst->c_hDC, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	HBITMAP oldBitMap = (HBITMAP)SelectObject(back_bufferDC, preBitMap);

	Rectangle(back_bufferDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	for (; itr != itr_end; itr++) {
		(*itr)->Render(back_bufferDC);
	}
	SendMessage(coreInst->c_hWnd, WM_CTLCOLORSTATIC, (WPARAM)back_bufferDC, (LPARAM)scoreLabel);
	
	BitBlt(coreInst->c_hDC, 0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, back_bufferDC, 0, 0, SRCCOPY);
	SelectObject(back_bufferDC, preBitMap);
	DeleteObject(preBitMap);
	ReleaseDC(coreInst->c_hWnd, back_bufferDC);
	DeleteDC(back_bufferDC);
}




void GameStageScene::Update(float frameTime) {

	std::vector<CLayer*>::iterator itr = refLayer.begin();
	std::vector<CLayer*>::iterator itr_end = refLayer.end();

	for (; itr != itr_end; itr++) {
		(*itr)->Update(frameTime);
	}
}

void GameStageScene::Input(float frameTime)
{
	player->Input(frameTime);
}

int GameStageScene::GetTileInfo(int x, int y)
{
	if ((y / TILE_SIZE) >= 24 || (x / TILE_SIZE) >= 30) return -1;
	if ((y / TILE_SIZE) < 0 || (x / TILE_SIZE) <0 ) return -1;

	return tile_arr[(y/ TILE_SIZE)][(x/ TILE_SIZE)];
}


LRESULT GameStageScene::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

CLayer * GameStageScene::GetLayerById(int id)
{
	std::vector<CLayer*>::iterator itr = refLayer.begin();
	std::vector<CLayer*>::iterator itr_end = refLayer.end();

	for (; itr != itr_end; itr++) {
		if ((*itr)->GetID() == id) {
			return *itr;
		}
	}

	return nullptr;
}
