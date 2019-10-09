#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#include <queue>
class TCPNetwork
{

private:
	static TCPNetwork* NetworkInst;
	WSAData wsaData; 
	SOCKADDR_IN servAddr;
	SOCKET servSock, clntSock;
	int m_port = 12345;
	int m_SendBufferSize = 1;

	std::queue<char*> SendPacketQueue;
public:
	TCPNetwork() {};
	~TCPNetwork() {};
	
	static TCPNetwork* GetInst() {
		if (!NetworkInst) {
			NetworkInst = new TCPNetwork;
		}
		return NetworkInst;
	}


	int Connect(const char* ip, int port);
	void ReceivePacket();
	void SendPacket();


};

