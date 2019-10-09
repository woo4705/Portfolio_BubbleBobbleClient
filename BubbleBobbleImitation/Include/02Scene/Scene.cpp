#include "Scene.h"


CScene::CScene()
{
}


CScene::~CScene()
{
}

int CScene::Init()
{
	//drawStaticObject
	return 0;
}

void CScene::Render()
{

}

void CScene::addLayer(CLayer * layer)
{
	refLayer.push_back(layer);
}
