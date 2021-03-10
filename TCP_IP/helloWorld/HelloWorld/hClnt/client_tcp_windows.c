#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void ErrorHandling(char* message);

int main(int argc, char* argv[]) {

	WSADATA wasData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen = 0;
	int idx = 0, readLen = 0;

	argc = 3;

	argv[0] = "./hclient";
	argv[1] = "127.0.0.1";
	argv[2] = "9190";

	// argv[0] : ��������, argv[1] : IP, argv[2] : Port Number
	if (argc != 3) {
		printf("Usage : %s <IP> <Port>\n", argv[0]);
		exit(1);
	}

	// winsock �ʱ�ȭ ���� üũ
	if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0)
		ErrorHandling("WSAStartup() error");

	// clnt ���� ����
	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hSocket == INVALID_SOCKET)
		ErrorHandling("hSocket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));

	// �����û connet() �Լ� ȣ��
	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		ErrorHandling("connect() error");
	}

	//networking...

	while (readLen = recv(hSocket, &message[idx++], 1, 0)) {

		if (readLen == -1)
			ErrorHandling("read() error");

		// read�Լ��� ȣ��Ƚ�� Ȯ��(�� �о���� bytes �� Ȯ��)
		strLen += readLen;
	}

	printf("Message from server : %s \n", message);
	printf("read() call count : %d \n", strLen);

	closesocket(hSocket);
	WSACleanup();
	return 0;

}

void ErrorHandling(char* message) {

	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
