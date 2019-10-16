#pragma once
#include "../01Core/Resource.h"
#include "../Core.h"
class CObj
{
public:
	CObj();
	~CObj();
	void SetSize(int w, int h);
	void SetRadius(int r);
	void Render(HDC back_hDC);
	
	void SetPosition(int x, int y) { this->x_pos = x; this->y_pos = y; };
	void SetTimePerFrame(float cnt) { this->time_per_frame = cnt; }
	void GetPosition(int&x, int&y) { x = this->x_pos; y = this->y_pos; }
	void GetSize(int &w, int &h) { w = this->width; h = this->height; }
	
	bool CheckAlive() { return this->isAlive; }
	void SetAlive(bool val) { this->isAlive = val; }

	virtual void Collision(int collision_layer_id, CObj* collision_obj) = 0;

	void UpdateFrame();

protected:
	int object_id;
	string img_id;
	short object_type;

	float x_pos=0, y_pos=0, z_order=0;
	int width=10, height=10;
	int radius=0;

	bool animated = false, horizontal_reversed = false;
	int frame_counter =0;
	int frame_num= 0;
	float acc_frame_time=0, time_per_frame=0;

	bool isAlive = true;

	Resource* resource_Inst = Resource::GetInst();
	CCore* core_Inst = CCore::GetInst();
};

