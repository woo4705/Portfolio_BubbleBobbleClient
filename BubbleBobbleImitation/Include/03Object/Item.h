#pragma once
#include "DynamicObject.h"
#include "PlayerCharacter.h"
class ItemObject :
	public DynamicObject
{
public:
	ItemObject();
	ItemObject(int item_id);
	void PickItem(PlayerCharacter* picked_player);
	~ItemObject();

	virtual void Update(float frameTime);	

private:
	int Item_ID;
	bool isFalling;
};

