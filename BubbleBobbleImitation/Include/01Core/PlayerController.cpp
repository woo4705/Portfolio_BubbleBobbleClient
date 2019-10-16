#include "PlayerController.h"

PlayerCharacter* PlayerController::m_myCharacter = nullptr;
void PlayerController::Init(PlayerCharacter* Owner)
{
	m_myCharacter = Owner;
	syncPacket = new GameSyncRequestPacket();

	syncPacket->InitAsDefaultInstance();
}

void PlayerController::Input(float frameTime)
{
	int x_pos, y_pos;
	int height, width;


	if (m_myCharacter == nullptr) {
		OutputDebugString(L"��Ʈ�ѷ��� ����ϴ� �÷��̾ ����\n");
		return;
	}

	if (GetAsyncKeyState('W') & 0x0001) {
		if (m_myCharacter->IsJumpable() == false) {
			return;
		}
		else {
			m_myCharacter->DoJump();
		}
	}

	if (GetAsyncKeyState('A') & 0x8000) {
		m_myCharacter->SetHorizontalReversed(false);
		m_myCharacter->AddAccFrameTime(frameTime);
		m_myCharacter->GetPosition(x_pos, y_pos);
		m_myCharacter->GetSize(height, width);

		if (m_myCharacter->CheckVaildMove(x_pos - 1, y_pos) == false){
			return;
		}
		else {
			m_myCharacter->Move(Move_Direction::Left, Velocity(200.f * frameTime, 0));
			
			/*
			ObjectEventRecord* eventRecord = syncPacket->add_eventrecordlist();
			eventRecord->set_eventtypecode(eventRecord->Move_Left);
			eventRecord->set_eventoccuredtime(m_packetFrameTime);
			*/
		}
	}

	if (GetAsyncKeyState('D') & 0x8000) {
		m_myCharacter->SetHorizontalReversed(true);
		m_myCharacter->AddAccFrameTime(frameTime);
		m_myCharacter->GetPosition(x_pos, y_pos);
		m_myCharacter->GetSize(height, width);

		if (m_myCharacter->CheckVaildMove(x_pos - 1, y_pos) == false) {
			return;
		}
		else {
			m_myCharacter->Move(Move_Direction::Right, Velocity(200.f * frameTime, 0));
			/*
			ObjectEventRecord* eventRecord = syncPacket->add_eventrecordlist();
			eventRecord->set_eventtypecode(eventRecord->Move_Left);
			eventRecord->set_eventoccuredtime(m_packetFrameTime);
			*/
		}
	}


	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		//TODO: ���� ���� ó��
		
	}
}
