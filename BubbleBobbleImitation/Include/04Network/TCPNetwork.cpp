#include <memory.h>
#include "TCPNetwork.h"


namespace Network {
	TCPNetwork* TCPNetwork::NetworkInst = NULL;

	int TCPNetwork::Connect(const char* ip, int port)
	{
		int initWinSockRes = WSAStartup(MAKEWORD(2, 0), &wsaData);
		servSock = socket(PF_INET, SOCK_STREAM, 0);
		ZeroMemory(&servAddr, sizeof(servAddr));
		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.s_addr = inet_addr(ip);
		servAddr.sin_port = htons(port);

		connect(clntSock, (struct sockaddr*) & servAddr, sizeof(servAddr));
		return false;
	}

	void TCPNetwork::ReceivePacket()
	{
		char* ReadBuffer = new char[m_RecvBufferSize];
	//	memset(ReadBuffer, 0, sizeof(m_RecvBufferSize));
		//int recvLen = recv(clntSock, ReadBuffer, sizeof(m_RecvBufferSize), 0);
		//TODO: 읽어들인 패킷을 Header로 정보를 받아들인후 패킷에 따른처리

		//m_RecvPacketQueue.push(ReadBuffer);
	}

	void TCPNetwork::SendPacket()
	{
		while (!m_SendPacketQueue.empty()) {
			char* data = m_SendPacketQueue.front();

			m_SendPacketQueue.pop();
			send(clntSock, data, sizeof(data), 0);
		}
	}

	/*
	메모리검사. 패킷을 queue에 넣고 이후 Send로 Pop하면 해체
	아니면 패킷 보내는 부분에서 RingBuffer를 활용?
	*/
	void TCPNetwork::AddPacketToSendQueue(char* packet)
	{
		SpinLockGuard lock(&m_CS);
		m_SendPacketQueue.push(packet);
	}

}