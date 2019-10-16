#pragma once
#include "../GameCommon.h"
#include "../03Object/PlayerCharacter.h"
#include "../04Network/PacketDefine.pb.h"
/*
[�����ϰ� �ִ� ��]
1. ���ӽ���
Ŭ���̾�Ʈ->����: ���ӽ���Request ��Ŷ����
����: ���ӽ���Request�� ���� ������ ���������� Response��Ŷ ����
����->Ŭ���̾�Ʈ: ���ӽ��� Response ���⿡�� �÷��̾� ������ ID(int16)�� ������ �����Ѵ�.

2. �����߰�
Ŭ���̾�Ʈ->����: �÷��̾� Input�� 
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

	//����ȭ��Ŷ �����ϱ�

	static PlayerController* Instance;
	float m_packetFrameTime = 0.f;
};

