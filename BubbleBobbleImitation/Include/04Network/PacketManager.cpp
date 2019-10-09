#include "PacketDefine.h"
#include "PacketManager.h"


void PacketManager::ProcessGameSyncPacket(char* pBuf, INT16 copySize)
{
	PLAYER_SYNC_NOTIFY_PACKET* pGameSyncReqPacket = reinterpret_cast<PLAYER_SYNC_NOTIFY_PACKET*>(pBuf);
	PLAYER_SYNC_NOTIFY_PACKET GameSyncNotifyPacket;

	if (copySize != 29) { //정책으로 지정된 패킷크기와 다르다면 잘못된 패킷
		return;
	}
	


}
