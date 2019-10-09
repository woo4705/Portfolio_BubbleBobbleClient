#include "Item.h"
#include "../02Scene/GameStageScene.h"

ItemObject::ItemObject()
{
}

ItemObject::ItemObject(int item_id) {
	switch (item_id) {
		case 1: {
			this->img_id = "banana_item";
			Item_ID = 1; //Enum으로 설정하자
			SetSize(48, 48);
			animated = false;
			isFalling = true;
			break;
			
		}
	}
}

void ItemObject::PickItem(PlayerCharacter * picked_player)
{
	switch (Item_ID) {
		case 1: {
			picked_player->PlusScore(500);
			isAlive = false;
			break;
		}
	}
}


ItemObject::~ItemObject() {
}

void ItemObject::Update(float frameTime) {
	for (int i = 0; i <= width / TILE_SIZE; i++) {
		if (GameStageScene::GetInst()->GetTileInfo((int)x_pos + i*TILE_SIZE, y_pos + height) != 0) {
			isFalling = false;
			return;
		}
	}
	isFalling = true;
	Move(Move_Direction::Down, Velocity(0, 200.f*frameTime)); //air flow영향?
}
