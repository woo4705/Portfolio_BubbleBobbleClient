#pragma once
#include<Windows.h>
class PacketManager
{
public:
	void ProcessEnterRoom(char* pBuf, INT16 copySize);
	void ProcessLeaveRoom(char* pBuf, INT16 copySize);
	void ProcessGameSyncPacket(char* pBuf, INT16 copySize);
	void ProcessGameStartPacket(char* pBuf, INT16 copySize);
	void ProcessGameEndPacket(char* pBuf, INT16 copySize);
};

