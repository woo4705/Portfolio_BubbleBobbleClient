#pragma once
#include <windows.h>
#include <fstream>
#include <utility>
#include "../01Core/Resource.h"
#include "../Core.h"
#include "../DataFile/StageData.pb.h"


class FileManager
{
private:
	static FileManager* FileMgr_Inst;
public:
	FileManager();
	~FileManager();

	static FileManager* GetFileMgrInst() {
		if (!FileMgr_Inst) {
			FileMgr_Inst = new FileManager();
		}
		return FileMgr_Inst;
	}

//	vector<MapData*> map;
	
private:
	ofstream ofs;
	ifstream ifs;
public:
	void LoadMapFile(const char* file_name, WholeStageData* stageData);

	
	
};

/*

class MapData {
public:
	//int **air_flow;
	//vector<EnemyCharacter> monsters;

	몬스터들을 담는 vector와 AI명령이 필요

int tile[25][31];
private:


public:
	MapData::MapData() {
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 30; j++) {
				tile[i][j] = 0;
			}
		}
	};


};


*/