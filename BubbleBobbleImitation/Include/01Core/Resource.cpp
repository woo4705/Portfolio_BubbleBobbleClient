#include "Resource.h"

Resource* Resource::resource_Inst = NULL;
unordered_map<string, LPCWSTR> Resource::resource_route_info = unordered_map<string, LPCWSTR>();
unordered_map<string, HBITMAP> Resource::loaded_resource = unordered_map<string, HBITMAP>();
Resource::Resource()
{
	InitResourceRouteData();
	InitLoadedResource();
}


Resource::~Resource()
{
}

void Resource::InitResourceRouteData()
{
	/*
	GetModuleFileName을 통해 실행파일의 경로를 얻고, 그것을 통해서 리소스들의 경로를 구하는 방법도 있다.
	디버그파일 혹은 작업 디렉토리의 상대경로와 실행파일의 경로는 다를 수 있음.
	GetCurrentDirectory: 현재 작업 디렉토리의 경로이다.
	*/

	resource_route_info.insert(pair<string, LPCWSTR>("Title_bg", L"../include/Bmp/Title_Bg.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("InGame_bg", L"../include/Bmp/InGame_Bg.bmp"));

	resource_route_info.insert(pair<string, LPCWSTR>("tile10", L"../include/Bmp/Tile/Tile1_0.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile11", L"../include/Bmp/Tile/Tile1_1.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile20", L"../include/Bmp/Tile/Tile2_0.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile21", L"../include/Bmp/Tile/Tile2_1.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile30", L"../include/Bmp/Tile/Tile3_0.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile31", L"../include/Bmp/Tile/Tile3_1.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile40", L"../include/Bmp/Tile/Tile4_0.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile41", L"../include/Bmp/Tile/Tile4_1.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile50", L"../include/Bmp/Tile/Tile5_0.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile51", L"../include/Bmp/Tile/Tile5_1.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile60", L"../include/Bmp/Tile/Tile6_0.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("tile61", L"../include/Bmp/Tile/Tile6_1.bmp"));

	resource_route_info.insert(pair<string, LPCWSTR>("1st_player", L"../include/Bmp/player1.bmp"));

	resource_route_info.insert(pair<string, LPCWSTR>("zen_chan_walk", L"../include/Bmp/ToyMonster.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("zen_chan_captured_1P", L"../include/Bmp/Zen_Chan_Captured_1P.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("zen_chan_thrown", L"../include/Bmp/Thrown_Zen_Chan.bmp"));

	resource_route_info.insert(pair<string, LPCWSTR>("fired_bubble", L"../include/Bmp/Fired_bubble.bmp"));
	resource_route_info.insert(pair<string, LPCWSTR>("floating_bubble", L"../include/Bmp/BubbleTmp.bmp"));

	resource_route_info.insert(pair<string, LPCWSTR>("banana_item", L"../include/Bmp/Banana_Item.bmp"));
}

void Resource::InitLoadedResource()
{
	loaded_resource.insert(pair<string, HBITMAP>("Title_bg", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("InGame_bg", NULL));

	loaded_resource.insert(pair<string, HBITMAP>("tile00", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile01", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile10", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile11", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile20", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile21", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile30", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile31", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile40", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile41", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile50", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("tile51", NULL));

	loaded_resource.insert(pair<string, HBITMAP>("1st_player", NULL));

	loaded_resource.insert(pair<string, HBITMAP>("zen_chan_walk", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("zen_chan_captured_1P", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("zen_chan_thrown", NULL));

	loaded_resource.insert(pair<string, HBITMAP>("fired_bubble", NULL));
	loaded_resource.insert(pair<string, HBITMAP>("floating_bubble", NULL));
}

LPCWSTR Resource::GetRoute(string key)
{
	return resource_route_info[key];;
}


HBITMAP Resource::GetResourceById(string key)
{
	if (loaded_resource[key] == NULL) {
		LPCWSTR route= resource_route_info[key];
		loaded_resource[key] = (HBITMAP)LoadImage(NULL, route, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	return loaded_resource[key];
}

void Resource::ClearLoadedResource(string key)
{
	loaded_resource[key] = NULL;
}

void Resource::RestoreLoadedResource(string key, HBITMAP bitmap)
{
	loaded_resource[key] = bitmap;
}
