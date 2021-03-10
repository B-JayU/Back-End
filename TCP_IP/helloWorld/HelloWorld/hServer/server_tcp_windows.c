#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void ErrorHandling(char* message);

int main(int argc, char* argv[]) {
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	int szClntAddr;
	char message[] = "Hello TCP/IP World";

	argc = 2;
	argv[0] = "./hserv";
	argv[1] = "9190";

	// argv[0] : �������� argv[1] : ��Ʈ��ȣ
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	// winsock �ʱ�ȭ
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		ErrorHandling("WSAStartup() error");
	}

	// TCP ���������� server ���� ����
	hServSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hServSock == INVALID_SOCKET) {
		ErrorHandling("socket() error");
	}

	// �ּ� ü�� ��� �ʱ�ȭ
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));

	//�ּ� �Ҵ�
	if (bind(hServSock, &servAddr, (SOCKADDR*)sizeof(servAddr)) == SOCKET_ERROR) {
		ErrorHandling("bind() error");
	}

	//���� ���ɻ��� Ȯ��
	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	// ���� ��û����
	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET)
		ErrorHandling("accept() error");

	// networking...
	send(hClntSock, message, sizeof(message), 0);

	// Close sockets
	closesocket(hClntSock);
	closesocket(hServSock);

	// unload WSA
	WSACleanup();

	return 0;
}

void ErrorHandling(char* message) {

	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}