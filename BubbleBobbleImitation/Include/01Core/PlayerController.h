#pragma once
#include "../GameCommon.h"
#include "../03Object/PlayerCharacter.h"
#include "../04Network/PacketDefine.pb.h"
/*
[구상하고 있는 모델]
1. 게임시작
클라이언트->서버: 게임시작Request 패킷보냄
서버: 게임시작Request에 대한 검증후 문제없으면 Response패킷 보냄
서버->클라이언트: 게임시작 Response 여기에서 플레이어 고유의 ID(int16)형 정보도 저정한다.

2. 게임중계
클라이언트->서버: 플레이어 Input의 
*/


class PlayerController
	
{
public:	
	void Init(PlayerCharacter* Owner);
	void Input(float frameTime);
	void ClearSyncPacket();
	void AddInputRecord(char input);

	static PlayerController* GetInst() {
		PlayerController inst;
		return &inst;
	}

	void SetSyncPacketInfo();


private:
	INT16 PlayerID=-1;
	UINT16 Life=3;
	INT32 Score=0;
	PlayerController() {};
	PlayerController(const PlayerController& other) {};
	~PlayerController() {};

	static PlayerCharacter* m_myCharacter;
	GameSyncRequestPacket* syncPacket;
	int record_cnt=0;

	//동기화패킷 정의하기

	static PlayerController* Instance;
	float m_packetFrameTime = 0.f;
};

