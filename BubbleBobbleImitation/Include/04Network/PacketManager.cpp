
#include "PacketManager.h"


void PacketManager::ProcessGameSyncPacket(char* pBuf, INT16 copySize)
{
	
	if (copySize != 29) { //정책으로 지정된 패킷크기와 다르다면 잘못된 패킷
		return;
	}
	


}
