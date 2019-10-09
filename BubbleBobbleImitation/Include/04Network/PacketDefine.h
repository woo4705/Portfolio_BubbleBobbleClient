#pragma once
#include <Windows.h>

const int MAX_PACKET_SIZE = 1024;

	enum class  PACKET_ID : UINT16 {

		/// ChatClient용 패킷 ID
		GAME_START_RESPONSE = 302,
		GAME_START_NOTIFY = 303,

		PLAYER_SYNC_REQUEST = 304,
		PLAYER_SYNC_NOTIFY = 305,
		ENEMY_SYNC_NOTIFY = 306,

		GAME_END_REQUEST = 311,
		GAME_END_RESPONSE = 312,
		GAME_END_NOTIFY = 313,
	};


#pragma pack(push,1)
	struct PACKET_HEADER
	{
		UINT16 PacketLength;
		UINT16 PacketId;
		UINT8 Type; 
	};

	//- 로그인 요청
	const int MAX_USER_ID_LEN = 20;


	struct LOGIN_RESPONSE_PACKET : public PACKET_HEADER {
	public:
		UINT16 Result;
	};


	struct PLAYER_SYNC_REQUEST_PACKET : public PACKET_HEADER {
		INT16 PlayerID;
		INT16 MoveOccured;
		FLOAT XMovement[10];
		FLOAT YMovement[10];
	};

	struct PLAYER_SYNC_NOTIFY_PACKET : public PACKET_HEADER {
		INT16 PlayerID;
		INT16 MoveOccured;
		FLOAT XMovement[10];
		FLOAT YMovement[10];
	};

	struct ENEMY_SYNC_NOTIFY_PACKET : public PACKET_HEADER {
		INT16 MonsterID;
		INT16 MoveOccured;
		FLOAT XMovement[10];
		FLOAT YMovement[10];
	};


	struct GAME_START_REQUEST_PACKET : public PACKET_HEADER {
		INT16 CharacterType;
	};

	struct GAME_START_NOTIFY_PACKET : public PACKET_HEADER {
		INT16 PlayerID;
	};

	struct GAME_START_RESPONSE_PACKET : public PACKET_HEADER {
		INT16 Result;
	};


	struct GAME_END_REQUEST_PACKET : public PACKET_HEADER {

	};

	struct GAME_END_NOTIFY_PACKET : public PACKET_HEADER {

	};

	struct GAME_END_RESPONSE_PACKET : public PACKET_HEADER {
		INT16 Result;
	};

#pragma pack(pop) 
