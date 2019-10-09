#include "FileManager.h"
#include <iostream>
#include <fstream>

FileManager* FileManager::FileMgr_Inst= NULL;

FileManager::FileManager()
{

}


FileManager::~FileManager()
{
}

void FileManager::LoadMapFile(const char* file_name, WholeStageData* stageData)
{
	fstream input(file_name, ios::in | ios::binary);
	if (!stageData->ParseFromIstream(&input)) {
		cerr << "Failed to parse StageData." << endl;
		return;
	}
	
}


