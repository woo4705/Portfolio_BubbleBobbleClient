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
	�̹����� ������ �����ϸ� �޸𸮸� ���� �����Ѵ�.
	�׷��� ������ �̹����� �ѹ� �ҷ����� ����Ű�� �������� �ؾ���
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
