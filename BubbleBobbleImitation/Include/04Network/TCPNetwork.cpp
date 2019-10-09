#include <memory.h>
#include "TCPNetwork.h"

TCPNetwork* TCPNetwork::NetworkInst = NULL;

int TCPNetwork::Connect(const char*  ip, int port)
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
	char* ReadBuffer = new char[4096];
	memset(ReadBuffer, 0, sizeof(4096));
	int recvLen = recv(clntSock, ReadBuffer, sizeof(4096), 0);
	//TODO: �о���� ��Ŷ�� Header�� ������ �޾Ƶ����� ��Ŷ�� ����ó��
}

void TCPNetwork::SendPacket()
{
	while (!SendPacketQueue.empty()) {
		char* data = SendPacketQueue.front();
		SendPacketQueue.pop();
		send(clntSock, data, sizeof(data), 0);
	}
}

