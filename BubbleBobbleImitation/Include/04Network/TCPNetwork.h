#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<WinSock2.h>
#include <queue>
#include "SpinLock.h"

namespace Network {
	class TCPNetwork
	{

	private:
		static TCPNetwork* NetworkInst;
		WSAData wsaData;
		SOCKADDR_IN servAddr;
		SOCKET servSock, clntSock;
		int m_port = 12345;
		int m_SendBufferSize = 2048;
		int m_RecvBufferSize = 2048;

		std::queue<char*> m_SendPacketQueue;
		std::queue<char*> m_RecvPacketQueue;
		SpinLockCriticalSection m_CS;
	public:
		TCPNetwork() {
			m_SendPacketQueue = std::queue<char*>();
			m_RecvPacketQueue = std::queue<char*>();
		};
		~TCPNetwork() {};

		//TODO: Thread-Safe«— ΩÃ±€≈Ê ∏∏µÈ±‚
		static TCPNetwork* GetInst() {
			if (!NetworkInst) {
				NetworkInst = new TCPNetwork;
			}
			return NetworkInst;
		}


		int Connect(const char* ip, int port);
		void ReceivePacket();
		void SendPacket();
		void AddPacketToSendQueue(char* packet);
		void GetPacketFromRecvQueue();


	};

}