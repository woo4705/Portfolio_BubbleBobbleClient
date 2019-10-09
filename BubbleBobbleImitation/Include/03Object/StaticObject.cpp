#include "StaticObject.h"

StaticObject::StaticObject()
{
}

StaticObject::StaticObject(int x, int y, int z_ord, bool ani)
{
	x_pos = x;
	y_pos = y;
	z_order = z_ord;
	animated = ani;
}

/*
	이미지를 생으로 참조하면 메모리를 많이 차지한다.
	그래서 참조할 이미지는 한번 불러오고 가리키는 방향으로 해야함
*/

StaticObject::StaticObject(int x, int y, int z_ord, bool ani, string img)
{
	img_id = img;
	x_pos = x;
	y_pos = y;
	z_order = z_ord;
	animated = ani;
}




StaticObject::~StaticObject()
{
}
